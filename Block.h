#ifndef Block_H
#define Block_H
#include <ncurses.h>
#include <string>

class Block{
	protected:
		std::string name;
		int y, x, yStart, xStart;
		WINDOW* curWin;
		char hor, ver;
		
	public:
		Block(std::string n);
		Block(std::string n, WINDOW* win, int yy, int xx, int yyStart, int xxStart, char horr, char verr); //initialize
		std::string getName(); //get block name
		
		//basic block function
		void drawBox(WINDOW * curWin, int y, int x, int yStart, int xStart, char horr, char verr);
		~Block();
};		
#endif