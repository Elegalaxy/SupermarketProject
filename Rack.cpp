#include <iostream>
#include "Rack.h"
#include "Product.h"
#include <string>
#include <vector>
using namespace std;

int Rack::rackID = 1;

Rack::Rack(): Block(name){
	currentID = 0;
	name = " ";
}

Rack::Rack(WINDOW * win, int yy, int xx, int yyStart, int xxStart, vector<Product> p): Block(name){
	currentID = rackID;
	rackID++;
	curWin = win;
	name = "Rack";
	items = p;
	y = yy;
	x = xx;
	yStart = yyStart;
	xStart = xxStart;
	drawBox(y, x, yStart, xStart);
	showProduct();
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

void Rack::drawBox(int y, int x, int yStart, int xStart){
	int yEnd = yStart + y;
	int xEnd = xStart + x;
	
	for(int i = yStart; i < yEnd; i++){
		for(int j = xStart; j < xEnd; j++){
			if(i == yStart || i == yEnd-1){
				mvwaddch(curWin, i, j, '=');
			}else if(j == xStart || j == xEnd-1){
				mvwaddch(curWin, i, j, '|');
			}
		}
	}
}

Product Rack::getProductByY(int y){
	return items[y];
}

void Rack::showProduct(){
	for(int i = 0; i < items.size(); i++){
		mvwprintw(curWin, yStart+i+1, xStart+1, items[i].getName().c_str());
	}
}

Rack::~Rack(){
	
}