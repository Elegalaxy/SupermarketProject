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
		
	public:
		static int rackID; //rack IDs
		Rack();
		Rack(WINDOW * win, int yy, int xx, int yyStart, int xxStart, std::vector<Product> p); //initialize
		int getID(); //return rack id
		void setRack(std::vector<Product> vec); //set rack's products
		Product getProductByY(int y);
		void showProduct();
		std::vector<Product> getProductList();
		~Rack();
};
#endif