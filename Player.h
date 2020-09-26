#ifndef Player_H
#define Player_H
#include <iostream>
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
			yLoc--;
			if(yLoc < 1)
				yLoc = 1;
		}
		
		void mvDown(){
			yLoc++;
			if(yLoc > yMax-2)
				yLoc = yMax-2;
		}
		
		void mvLeft(){
			xLoc--;
			if(xLoc < 1)
				xLoc = 1;
		}
		
		void mvRight(){
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
				case 10: //Enter
					addItem("Something");
					addItem();
					addItem("Bread");
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