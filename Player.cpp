#include <iostream>
#include "Player.h"
#include "Product.h"
#include "Rack.h"
#include <ncurses.h>
#include <vector>
#include <string>
using namespace std;

//initialize
Player::Player(WINDOW * win, int y, int x, char c, vector<vector<Rack>> r){
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

Product Player::getProductByRack(int y, Rack* r){
	int start, end;
	start = r->getLocation('y');
	cout << y-start-1;
	Product p;
	return p;//r->getProductByY(y-start-1);
}

Rack Player::returnRackByID(int ID){
	for(int i = 0; i < rack.size(); i++){
		for(int j = 0; j < rack.size(); j++){
			if(rack[i][j].getID() == ID) return rack[i][j];
		}
	}
	Rack n;
	return n;
}

int Player::getRackIDByLoc(int y, int x){
	int yStart, xStart, yEnd, xEnd;
	for(int i = 0; i < rack.size(); i++){
		for(int j = 0; j < rack[i].size(); j+=2){
			yStart = rack[i][j].getLocation('y');
			xStart = rack[i][j].getLocation('x');
			yEnd = yStart + rack[i][j].getSize('y')-1;
			xEnd = xStart + rack[i][j].getSize('x') + rack[i][j+1].getSize('x');
			if(y >= yStart && y <= xStart && x >= xStart && x <= xEnd)
				return rack[i][j].getID();
		}
	}
	return 0;
}


Product Player::getBlockDetail(int y, int x){
	int current;
	Rack curRack;
	Product n;
	current = getRackIDByLoc(y, x);
	
	if(!current) return n;
	else{
		curRack = returnRackByID(current);
		return n;//getProductByRack(y, &curRack);
	}
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
			cout << checkBlock(yLoc, xLoc, '|').getName();
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

Player::~Player(){
	
}