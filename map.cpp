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
	getmaxyx(stdscr, yMax, xMax);
	WINDOW * map = terminal.createWin(10, 20, (yMax/2)-5, (xMax/2)-10);
	bool game = true;
	
	terminal.getKey();
	return 0;
}