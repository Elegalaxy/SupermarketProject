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
	//cout << yMax << " " << xMax;
	WINDOW * map = terminal.createWin(yMax, xMax-1, 0, 1);
	bool game = true;
	
	Player * p = new Player(map, yMax-6, 4, '@');
	do {
		p->display();
		wrefresh(map);
	}while(p->getmv() != 'x');
	
	
	
	terminal.getKey();
	return 0;
}