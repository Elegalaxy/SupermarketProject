#ifndef Block_H
#define Block_H
#include <ncurses.h>
#include <string>

class Block{
	protected:
		std::string name;
	public:
		Block(std::string n); //initialize
		//set get block name
		std::string getName();
		
		//basic block function
		void drawBox(WINDOW * win, int y, int x, int yStart, int xStart, char c);
		void trigger();
		~Block();
};		
#endif