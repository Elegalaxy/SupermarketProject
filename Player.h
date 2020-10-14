#ifndef Player_H
#define Player_H
#include <iostream>
#include "Product.h"
#include "Rack.h"
#include <ncurses.h>
#include <vector>
#include <string>

class Player{
	private:
		int xLoc, yLoc, xMax, yMax;
		char character;
		WINDOW * curwin;
		std::string inventory = "";
		void checkBlock();
		std::vector<std::vector<Rack>> rack;
		Product n;
		
	public:
		Player(WINDOW * win, int y, int x, char c, std::vector<std::vector<Rack>> r); //initialize
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
		
		Product checkBlock(int y, int x, char c);
		Product trigger(int y, int x);
		int getRackIDByLoc(int y, int x);
		Product getProductByRack(int y, Rack* r);
		Rack returnRackByID(int ID);

		~Player();
};
#endif