#include <iostream>
#include "Terminal.h"
#include "Product.h"
#include "Player.h"
#include "Rack.h"
#include <ncurses.h>
#include <string>
using namespace std;

//just for testing the location
int main(){
	Terminal terminal;
	WINDOW * map = terminal.createWin(20, 20, 1, 1);
	
	Product p("Hi");
	vector<Product> pl;
	pl.push_back(p);
	Rack r(map, 5, 5, 3, 3, pl);
	vector<vector<Rack>> rl;
	vector<Rack> temp;
	
	temp.push_back(r);
	rl.push_back(temp);
	
	Player * pr = new Player(map, 2, 2, '@', rl);
	do {
		pr->display();
		wrefresh(map);
	}while(pr->getmv() != 'x');

	return 0;
}