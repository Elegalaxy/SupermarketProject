#include <iostream>
#include "Player.h"
#include "Product.h"
#include "Rack.h"
#include <ncurses.h>
#include <vector>
#include <string>
using namespace std;

//initialize
Player::Player(WINDOW * win, int y, int x, char c, Rack r){
	curwin = win;
	yLoc = y;
	xLoc = x;
	getmaxyx(curwin, yMax, xMax);
	keypad(curwin, true);
	character = c;
	rack = r;
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

Product Player::checkBlock(int y, int x, char c){
	char cUp = mvwinch(curwin, y-1, x);
	char cRight = mvwinch(curwin, y, x+1);
	char cDown = mvwinch(curwin, y+1, x);
	char cLeft = mvwinch(curwin, y, x-1);
	if(cUp == c)
		return getBlockDetail(y-1, x);
	else if(cRight == c)
		return getBlockDetail(y, x+1);
	else if(cDown == c)
		return getBlockDetail(y+1, x);
	else if(cLeft == c)
		return getBlockDetail(y, x-1);
	else{
		Product n;
		return n;
	}
}

Product Player::getBlockDetail(int y, int x){
	Product n;
	return n;
}

int Player::getmv(){
	int choice = wgetch(curwin);
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
		case 10: //Enter
			//drawBox(curwin,5,5,2,2);
			//cout << checkBlock(yLoc, xLoc, '|').getName();
			cout << getRackIDByLoc(yLoc, xLoc, rack);
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
void Player::addItem(){
	inventory = "";
}

bool Player::addItem(string item){
	if(inventory == "")
		inventory = item;
	else
		return false;
	
	return true;
}

string Player::getInventory(){
	inventory = "";
	return inventory;
}

int getRackIDByLoc(int y, int x, vector<vector<Rack>> r){
	int yStart, xStart, yEnd, xEnd;
	for(int i = 0; i < r.size(); i++){
		for(int j = 0; j < r[i].size(); j++){
			yStart = r[i][j].getLocation('y');
			xStart = r[i][j].getLocation('x');
			yEnd = yStart + r[i][j].getSize('y');
			xEnd = xStart + r[i][j].getSize('x');
			if(y >= yStart && y <= xStart && x >= xStart && x <= xEnd)
				cout << r[i][j].getID();
		}
	}
	return 0;
}

Player::~Player(){
	
}