#ifndef Terminal_H
#define Terminal_H
#include <ncurses.h>

class Terminal{
	public:
		Terminal(); //initialize
		void start();
		void end();
		int getKey(); //get input
		WINDOW * createWin(int y, int x, int startY, int startX); //create window
		~Terminal();
};
#endif