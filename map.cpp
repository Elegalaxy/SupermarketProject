#include "Terminal.h"
#include "Player.h"
#include <ncurses.h>
#include <string>
using namespace std;

extern bool menu();

int main(){
	Terminal terminal;
	if(!menu()){
		refresh();
		return 0;
	}
		
	int y, x, yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);//30 120
	y = (yMax-30)/2;
	x = (xMax-118)/2;
	//cout << yMax << " " << xMax << " " << y << " " << x;
	
	WINDOW * map = terminal.createWin(30, 120, y, x);
	
	Player * p = new Player(map, 2/*y+22*/, 2/*4*/, '@');
	do {
		p->display();
		wrefresh(map);
	}while(p->getmv() != 'x');
	
	//terminal.getKey();
	return 0;
}