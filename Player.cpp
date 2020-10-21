#include <iostream>
#include "Player.h"
#include "Product.h"
#include "Rack.h"
#include "Counter.h"
#include "Bin.h"
#include <ncurses.h>
#include <vector>
#include <string>

using namespace std;

//initialize
Player::Player(WINDOW * win, int y, int x, char c, vector<vector<Rack>> *r, Counter cc, Bin bb, bool *game){
	curwin = win;
	yLoc = y;
	xLoc = x;
	getmaxyx(curwin, yMax, xMax);
	keypad(curwin, true);
	character = c;
	rack = r;
	bin = bb;
	counter = cc;
	score = 0;
	mvwprintw(curwin, 2, 120 -11-4, "%s", "Score:");
	mvwprintw(curwin, 2, 120 -9, "%d", score);
	curGame = game;
}

//movement
void Player::mvUp(){
	if(mvwinch(curwin, yLoc-1, xLoc) == 32)
		yLoc--;
}

void Player::mvDown(){
	if(mvwinch(curwin, yLoc + 1, xLoc) == 32)
		yLoc++;
}

void Player::mvLeft(){
	if(mvwinch(curwin, yLoc, xLoc - 1) == 32)
		xLoc--;
}

void Player::mvRight(){
	if(mvwinch(curwin, yLoc, xLoc + 1) == 32)
		xLoc++;
}

Product Player::getProductByRack(int y, Rack* r){
	int start;
	start = r->getLocation('y');
	return r->getProductByY(y-start-1);
}

Rack Player::returnRackByID(int ID){
	for(int i = 0; i < rack->size(); i++){
		for(int j = 0; j < (*rack)[i].size(); j++){
			if((*rack)[i][j].getID() == ID) return (*rack)[i][j];
		}
	}
	Rack n;
	return n;
}

int Player::getRackIDByLoc(int y, int x){
	int yStart, xStart, yEnd, xEnd;
	for(int i = 0; i < rack->size(); i++){
		for(int j = 0; j < (*rack)[i].size(); j++){
			yStart = (*rack)[i][j].getLocation('y');
			xStart = (*rack)[i][j].getLocation('x');
			yEnd = yStart + (*rack)[i][j].getSize('y')-1;
			xEnd = xStart + (*rack)[i][j].getSize('x');
			if(y >= yStart && y <= yEnd && x >= xStart && x <= xEnd) return (*rack)[i][j].getID();
		}
	}
	return 0;
}

void Player::updateScore(){
	mvwprintw(curwin, 2, 120 -9, "%s", "      ");
	mvwprintw(curwin, 2, 120 -9, "%d", score);
}

Product Player::trigger(int y, int x){
	int current = getRackIDByLoc(y, x);

	if(!current){
		if(y >= counter.getLocation('y') && x >= counter.getLocation('x') && y <= counter.getLocation('y') + counter.getSize('y') && x <= counter.getLocation('x') + counter.getSize('x')){
			if(counter.checkItem(inventory)){
				score++;
				updateScore();
				counter.removeOrder(inventory);
				inventory = "";
				mvwprintw(curwin, yMax-6, xMax-11, "%s", "          ");
				mvwprintw(curwin, yMax-6, xMax-16, "%s", "    ");
				if(score == 2) {
					win();
					wrefresh(curwin);
					*curGame = false;
				}
			}
		}else if(y >= bin.getLocation('y') && x >= bin.getLocation('x') && y <= bin.getLocation('y') + bin.getSize('y') && x <= bin.getLocation('x') + bin.getSize('x')){
			inventory = "";
			mvwprintw(curwin, yMax-6, xMax-11, "%s", "          ");
			mvwprintw(curwin, yMax-6, xMax-16, "%s", "    ");
			score--;
			updateScore();
		}
	}else{
		Rack curRack = returnRackByID(current);
		return getProductByRack(y, &curRack);
	}
	return n;
}

Product Player::checkBlock(int y, int x){
	char cUp = mvwinch(curwin, y-1, x);
	char cRight = mvwinch(curwin, y, x+1);
	char cDown = mvwinch(curwin, y+1, x);
	char cLeft = mvwinch(curwin, y, x-1);
	char c[] = {'|', '*', '-'};
	for(int i = 0; i < sizeof(c)/sizeof(c[0]); i++){
		if(cUp == c[i]) return trigger(y-1, x);
		else if(cRight == c[i]) return trigger(y, x+1);
		else if(cDown == c[i]) return trigger(y+1, x);
		else if(cLeft == c[i]) return trigger(y, x-1);
	}
	return n;
}

int Player::getmv(){
	int choice = wgetch(curwin);
	string n;
	mvwaddch(curwin, yLoc, xLoc, ' ');
	switch(choice){
		case KEY_UP:
			mvUp();
			break;
		case KEY_DOWN:
			mvDown();
			break;
		case KEY_LEFT:
			mvLeft();
			break;
		case KEY_RIGHT:
			mvRight();
			break;
		case 'z': //Enter
			n = checkBlock(yLoc, xLoc).getName();
			if(n != "") addItem(n);
			break;
		default:
			break;
	}
	return choice;
}

void Player::display(){
	mvwaddch(curwin, yLoc, xLoc, character);
}

int Player::getPos(char p){
	if(p == 'y') return yLoc;
	else if(p == 'x') return xLoc;
	else return 0;
}

//inventory
bool Player::addItem(string item){
	if(inventory == ""){
		inventory = item;
		mvwprintw(curwin, yMax-6, xMax-16, "%s", "    ");
		mvwprintw(curwin, yMax-6, xMax-11, "%s", "          ");
		wrefresh(curwin);
		mvwprintw(curwin, yMax-6, xMax-11, inventory.c_str());
		return true;
	}
	else{
		mvwprintw(curwin, yMax-6, xMax-16, "%s", "FULL");
		return false;
	}
}

string Player::getInventory(){
	return inventory;
}

void Player::win(){
	int starty = 11, startx = 53;
	int endy = 16, endx = 67;
	for(int i = starty; i <= endy; i++){
		for(int j = startx; j <= endx; j++){
			mvwaddch(curwin, i, j, ' ');
			if(i == starty || j == startx || i == endy || j == endx){
				mvwaddch(curwin, i, j, '*');
			}
			else if(i == starty+2 && j == (startx+endx)/2-1){
				mvwprintw(curwin, i, j, "%s", "You");
				j+=2;
			}else if(i == starty+3 && j == (startx+endx)/2-1){
				mvwprintw(curwin, i, j, "%s", "Win");
				j+=2;
			}
		}
	}
}

Player::~Player(){
	
}