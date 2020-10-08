#ifndef Player_H
#define Player_H
#include <iostream>
#include "Product.h"
#include <ncurses.h>
#include <string>

class Player{
	private:
		int xLoc, yLoc, xMax, yMax;
		char character;
		WINDOW * curwin;
		std::string inventory = "";
		void checkBlock();
		
	public:
		Player(WINDOW * win, int y, int x, char c); //initialize
		//movement
		void mvUp();
		void mvDown();
		void mvLeft();
		void mvRight();
		int getmv();
		void display();
		int getPos(char p); //get position base on y or x
		
		//inventory
		void addItem(); //remove item
		bool addItem(std::string item); //add item
		std::string getInventory(); //return item
		Product checkBlock(int y, int x);
		Product getBlockDetail(int y, int x);

		~Player();
};
#endif