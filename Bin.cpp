#include <iostream>
#include "Bin.h"
using namespace std;

Bin::Bin(): Block(name){
	name = "Bin";
}

Bin::Bin(WINDOW * win, int yy, int xx, int yyStart, int xxStart): Block(name, win, yy, xx, yyStart, xxStart, '-', '|'){
	name = "Bin";
	mvwprintw(curWin, yStart+1, xStart+1, name.c_str());
}