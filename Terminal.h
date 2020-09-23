#ifndef Terminal_H
#define Terminal_H

#include <ncurses.h>

class Terminal{
	public:
		Terminal(){
			start();
		}
		~Terminal(){
			end();
		}
				
		void start(){
			initscr();
			cbreak(); //ctrl C exit program
			//raw(); //take all input as input
			noecho(); //what user type dont show up
			keypad(stdscr, true);
		}
		
		void end(){
			endwin();
		}
		
		int getKey(){
			return getch();
		}
		
		WINDOW * createWin(int y, int x, int startY, int startX){
			WINDOW * win = newwin(y, x, startY, startX);
			box(win, 0, 0);
			keypad(win, true);
			refresh();
			wrefresh(win);
			return win;
		}
};

#endif