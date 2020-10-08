#ifndef Rack_H
#define Rack_H
#include <ncurses.h>
#include "Block.h"
#include "Product.h"
#include <string>
#include <vector>

class Rack: public Block{
	private:
		int currentID;
		std::vector<Product> items;
		int y, x, yStart, xStart;
	
	public:
		static int rackID; //rack IDs
		Rack(WINDOW *win, int yy, int xx, int yyStart, int xxStart);//, Product p); //initialize
		int getID(); //return rack id
		void setRack(std::vector<Product> vec); //set rack's products
		int getLocation(char p); //return rack start location
		int getSize(char s); //return rack size
		void drawBox(WINDOW * win, int y, int x, int yStart, int xStart);
		~Rack();
};
#endif