#include <iostream>
#include <ncurses.h>
#include "Terminal.h"
using namespace std;

Terminal::Terminal(){
	start();
}

void Terminal::start(){
	initscr();
	cbreak(); //ctrl C exit program
	//raw(); //take all input as input
	noecho(); //what user type dont show up
	keypad(stdscr, true);
}

void Terminal::end(){
	endwin();
}

int Terminal::getKey(){
	return getch();
}

WINDOW * Terminal::createWin(int y, int x, int startY, int startX){
	WINDOW * win = newwin(y, x, startY, startX);
	box(win, 0, 0);
	keypad(win, true);
	refresh();
	wrefresh(win);
	return win;
}

Terminal::~Terminal(){
	end();
}