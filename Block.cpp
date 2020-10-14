#include <iostream>
#include "Block.h"
#include <string>
using namespace std;

Block::Block(string n){
	name = n;
}

Block::Block(string n, WINDOW* win, int yy, int xx, int yyStart, int xxStart, char horr, char verr){
	name = n;
	curWin = win;
	y = yy;
	x = xx;
	yStart = yyStart;
	xStart = xxStart;
	hor = horr;
	ver = verr;
	drawBox(curWin, y, x, yStart, xStart, hor, ver);
}

string Block::getName(){
	return name;
}

void Block::drawBox(WINDOW * curWin, int y, int x, int yStart, int xStart, char horr, char verr){
	int yEnd = yStart + y;
	int xEnd = xStart + x;
	
	for(int i = yStart; i < yEnd; i++){
		for(int j = xStart; j < xEnd; j++){
			if(i == yStart || i == yEnd-1){
				mvwaddch(curWin, i, j, hor);
			}else if(j == xStart || j == xEnd-1){
				mvwaddch(curWin, i, j, ver);
			}
		}
	}
}

Block::~Block(){
	
}