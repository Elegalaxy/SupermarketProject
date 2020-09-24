#ifndef Player_H
#define Player_H
#include <ncurses.h>

class Player{
	private:
		int xLoc, yLoc, xMax, yMax;
		char character;
		WINDOW * curwin;
	
	public:
		Player(WINDOW * win, int y, int x, char c){
			curwin = win;
			yLoc = y;
			xLoc = x;
			getmaxyx(curwin, yMax, xMax);
			keypad(curwin, true);
			character = c;
		}
		
		void mvUp(){
			//mvwaddch(curwin, yLoc, xLoc, ' ');
			yLoc--;
			if(yLoc < 1)
				yLoc = 1;
		}
		
		void mvDown(){
			//mvwaddch(curwin, yLoc, xLoc, ' ');
			yLoc++;
			if(yLoc > yMax-2)
				yLoc = yMax-2;
		}
		
		void mvLeft(){
			//mvwaddch(curwin, yLoc, xLoc, ' ');
			xLoc--;
			if(xLoc < 1)
				xLoc = 1;
		}
		
		void mvRight(){
			//mvwaddch(curwin, yLoc, xLoc, ' ');
			xLoc++;
			if(xLoc > xMax-2)
				xLoc = xMax-2;
		}
		
		int getmv(){
			int choice = wgetch(curwin);
			mvwaddch(curwin, yLoc, xLoc, ' ');
			switch(choice){
				case KEY_UP:
					mvUp();
					break;
				case KEY_DOWN:
					mvDown();
					break;
				case KEY_LEFT:
					mvLeft();
					break;
				case KEY_RIGHT:
					mvRight();
					break;
				default:
					break;
			}
			return choice;
		}
		
		void display(){
			mvwaddch(curwin, yLoc, xLoc, character);
		}
	
		~Player();
};
#endif