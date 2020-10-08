#include <iostream>
#include "Player.h"
#include "Product.h"
#include <ncurses.h>
#include <string>
using namespace std;

//initialize
Player::Player(WINDOW * win, int y, int x, char c){
	curwin = win;
	yLoc = y;
	xLoc = x;
	getmaxyx(curwin, yMax, xMax);
	keypad(curwin, true);
	character = c;
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

Product Player::checkBlock(int y, int x){
	char cUp = mvwinch(curwin, y-1, x);
	char cRight = mvwinch(curwin, y, x+1);
	char cDown = mvwinch(curwin, y+1, x);
	char cLeft = mvwinch(curwin, y, x-1);
	if(cUp != ' ')
		return getBlockDetail(y-1, x);
	else if(cRight != ' ')
		return getBlockDetail(y, x+1);
	else if(cDown != ' ')
		return getBlockDetail(y+1, x);
	else if(cLeft != ' ')
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
			cout << checkBlock(yLoc, xLoc).getName();
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