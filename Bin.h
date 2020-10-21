#ifndef Bin_H
#define Bin_H
#include <ncurses.h>
#include "Block.h"

class Bin: public Block{
	public:
		Bin();
		Bin(WINDOW * win, int yy, int xx, int yyStart, int xxStart); //initialize
		~Bin();
};
#endif