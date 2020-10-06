#ifndef Player_H
#define Player_H
#include <iostream>
#include "Draw.h"
#include <ncurses.h>
#include <string>

class Player{
	private:
		int xLoc, yLoc, xMax, yMax;
		char character;
		WINDOW * curwin;
		std::string inventory = "";
		
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
			if(mvwinch(curwin, yLoc-1, xLoc) == 32)
				yLoc--;
		}
		
		void mvDown(){
			if(mvwinch(curwin, yLoc + 1, xLoc) == 32)
				yLoc++;
		}
		
		void mvLeft(){
			if(mvwinch(curwin, yLoc, xLoc - 1) == 32)
				xLoc--;
		}
		
		void mvRight(){
			if(mvwinch(curwin, yLoc, xLoc + 1) == 32)
				xLoc++;
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
				case 10: //Enter
					//drawBox(curwin,5,5,2,2);
					break;
				default:
					break;
			}
			return choice;
		}
		
		void display(){
			mvwaddch(curwin, yLoc, xLoc, character);
		}
	
		void addItem(){
			inventory = "";
		}
		
		bool addItem(std::string item){
			if(inventory == "")
				inventory = item;
			else
				return false;
			
			return true;
		}
		
		std::string getInventory(){
			return inventory;
		}
		
		int getPos(char p){
			if(p == 'y') return yLoc;
			else if(p == 'x') return xLoc;
			else return 0;
		}
		
		/*bool removeItem(std::string item){
			for(int i = 0; i < targets.size(); i++){
				if(targets[i] == item){
					targets.erase(i);
					return true;
				}
			}
			return false;
		}*/
	
		~Player();
};
#endif