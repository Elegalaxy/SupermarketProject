#include <iostream>
#include "Rack.h"
#include "Product.h"
#include <string>
#include <vector>
using namespace std;

int Rack::rackID = 1;

Rack::Rack(): Block(name){
	currentID = 0;
	name = "";
}

Rack::Rack(WINDOW * win, int yy, int xx, int yyStart, int xxStart, vector<Product> p): Block(name, win, yy, xx, yyStart, xxStart, '=', '|'){
	currentID = rackID;
	rackID++;
	name = "Rack";
	items = p;
	showProduct();
}

int Rack::getID(){
	return currentID;
}

Product Rack::getProductByY(int y){
	return items[y];
}

void Rack::showProduct(){
	for(int i = 0; i < items.size(); i++){
		mvwprintw(curWin, yStart+i+1, xStart+1, items[i].getName().c_str());
	}
}

vector<Product> Rack::getProductList(){
	return items;
}

Rack::~Rack(){
	
}