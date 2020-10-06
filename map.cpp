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
	int rackY;
	const int rackX = 5;
	rackY = 5;
	
	getmaxyx(stdscr, yMax, xMax);//30 120
	y = (yMax-30)/2;
	x = (xMax-118)/2;
	//cout << yMax << " " << xMax << " " << y << " " << x;
	WINDOW * map = terminal.createWin(30, 120, y, x);
	
	//rack
	drawBox(map ,rackY, rackX, 1, 6);
	drawBox(map ,rackY, rackX, 1, 16);
	drawBox(map ,rackY, rackX, 1, 26);
	drawBox(map ,rackY, rackX, 1, 36);
	
	//player
	Player * p = new Player(map, y+24, 4, '@');
	do {
		p->display();
		wrefresh(map);
	}while(p->getmv() != 'x');
	
	//terminal.getKey();
	return 0;
}