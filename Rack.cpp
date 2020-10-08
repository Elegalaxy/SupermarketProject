#include <iostream>
#include "Rack.h"
#include "Product.h"
#include <string>
#include <vector>
using namespace std;

int Rack::rackID = 1;

Rack::Rack(WINDOW * win, int yy, int xx, int yyStart, int xxStart): Block(name){//, vector<Product> p){
	currentID = rackID;
	rackID++;
	name = "Rack";
	//items = p;
	y = yy;
	x = xx;
	yStart = yyStart;
	xStart = xxStart;
	drawBox(win ,y, x, yStart, xStart);
}

int Rack::getID(){
	return currentID;
}

int Rack::getLocation(char p){
	switch(p){
		case 'y':
			return yStart;
		case 'x':
			return xStart;
		default:
			return 0;
	}
}

int Rack::getSize(char s){
	switch(s){
		case 'y':
			return y;
		case 'x':
			return x;
		default:
			return 0;
	}
}

void Rack::drawBox(WINDOW * win, int y, int x, int yStart, int xStart){
	int yEnd = yStart + y;
	int xEnd = xStart + x;
	
	for(int i = yStart; i < yEnd; i++){
		for(int j = xStart; j < xEnd; j++){
			if(i == yStart || i == yEnd-1){
				mvwaddch(win, i, j, '=');
			}else if(j == xStart || j == xEnd-1){
				mvwaddch(win, i, j, '|');
			}
		}
	}
}

Rack::~Rack(){
	
}