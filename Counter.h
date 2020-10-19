#ifndef Counter_H
#define Counter_H
#include <ncurses.h>
#include "Block.h"
#include "Product.h"
#include "Rack.h"
#include <vector>
#include <string>

class Counter: public Block{
	private:
		std::vector<Product> require;
		std::vector<std::vector<Product>> products;
		std::vector<Product> temp;
		int yWord, xWord;
	public:
		Counter();
		Counter(WINDOW * win, int yy, int xx, int yyStart, int xxStart, std::vector<std::vector<Rack>> Rs); //initialize
		void drawBox(WINDOW * curWin, int y, int x, int yStart, int xStart, char horr, char verr);
		bool checkItem(std::string item);
		void addOrder();
		void removeOrder(std::string);
};

#endif