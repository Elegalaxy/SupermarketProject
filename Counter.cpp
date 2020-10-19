#include <iostream>
#include <ncurses.h>
#include "Counter.h"
#include "Product.h"
#include <string>
using namespace std;

Counter::Counter(): Block(name){
	name = "";
}

Counter::Counter(WINDOW * win, int yy, int xx, int yyStart, int xxStart, vector<vector<Rack>> Rs): Block(name, win, yy, xx, yyStart, xxStart, '*', '|'){
	name = "Counter";
	mvwprintw(curWin, yStart+1, xStart+1, name.c_str());
	drawBox(curWin, y, x, yStart, xStart, hor, ver);
	yWord = 3;
	xWord = 120 - 11 - 3;
	srand (time(NULL));
	for(int i = 0; i < Rs.size(); i++){
		temp.clear();
		for(int j = 0; j < Rs[i].size(); j++){
			temp = Rs[i][j].getProductList();
		}
		products.push_back(temp);
	}
	addOrder();
}

void Counter::drawBox(WINDOW * curWin, int y, int x, int yStart, int xStart, char horr, char verr){
	int yEnd = yStart + y;
	int xEnd = xStart + x;
	
	for(int i = yStart; i < yEnd; i++){
		for(int j = xStart; j < xEnd; j++){
			if(i == yStart){
				mvwaddch(curWin, i, j, hor);
			}else if(j == xStart || j == xEnd-1){
				mvwaddch(curWin, i, j, ver);
			}
		}
	}
}

bool Counter::checkItem(string item){
	//cout << require[0].getName();
	if(item == "") return false;
	for(int i = 0; i < require.size(); i++){
		if(require[i].getName() == item){
			removeOrder(item);
			return true;
		}
	}
	return false;
}

void Counter::addOrder(){
	if(require.size() < 5){
		int i = rand()%products.size(), j = rand()%products[0].size();
		require.push_back(products[i][j]);
	}
	mvwprintw(curWin, yWord, xWord, require[require.size()-1].getName().c_str());
}

void Counter::removeOrder(string s){
	for(int i = 0; i < require.size(); i++){
		if(require[i].getName() == s){
			require.erase(require.begin()+i);
			mvwprintw(curWin, yWord + i, xWord, "%s", "          ");
			return;
		}
	}
}
