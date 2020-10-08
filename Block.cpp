#include <iostream>
#include "Block.h"
#include <string>
using namespace std;

Block::Block(string n){
	name = n;
}

string Block::getName(){
	return name;
}

void Block::drawBox(WINDOW * win, int y, int x, int yStart, int xStart, char c){
	int yEnd = yStart + y;
	int xEnd = xStart + x;
	
	for(int i = yStart; i < yEnd; i++){
		for(int j = xStart; j < xEnd; j++){
			if(i == yStart || i == yEnd-1 || j == xStart || j == xEnd-1){
				mvwaddch(win, i, j, c);
			}
		}
	}
}

void Block::trigger(){
	
}

Block::~Block(){
	
}