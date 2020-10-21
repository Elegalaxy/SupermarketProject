#include "Terminal.h"
#include <ncurses.h>
#include <string>
using namespace std;

bool menu(){
	Terminal terminal;
	int y, x, yMax = 28, xMax = 118;
	WINDOW * menu = terminal.createWin(yMax, xMax, 1, 1);
	mvwprintw(menu, 2, 6, "%s", "Instruction: During Covid-19 We can not go inside the supermarket.");
	mvwprintw(menu, 3, 6, "%s", "Due to this issue we have to tell our supermarket helper what the product that we want.");
	mvwprintw(menu, 4, 6, "%s", "We have to control the supermarket helper to pick the product for the customers.");
	mvwprintw(menu, 5, 6, "%s", "Use keypad to control the player and use 'Z' to select the product that we want,");
	mvwprintw(menu, 6, 6, "%s", "then put it to the counter to score a point.");
	mvwprintw(menu, 7, 6, "%s", "You can only grab one thing at a time and cannot put it back.");
	mvwprintw(menu, 8, 6, "%s", "If your hand is full then you need to throw it into the bin :p");
	mvwprintw(menu, 9, 6, "%s", "Score 10 points to win the game");
	mvwprintw(menu, 10, 6, "%s", "You can quit in the middle of the game by pressing 'Q'");
	bool game = true;

	string choices[2] = {"Start", "Quit"};
	int choice;
	int highlight = 0;
	
	while(game){
		for(int i = 0; i < 2; i++){
			if(i == highlight)
				wattron(menu, A_REVERSE);
			mvwprintw(menu, yMax/2-1+i, xMax/2-3, choices[i].c_str());
			wattroff(menu, A_REVERSE);
		}
		
		choice = wgetch(menu);
		switch (choice){
			case KEY_UP:
				highlight--;
				if(highlight == -1)
					highlight = 0;
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight == 2)
					highlight = 1;
				break;
			default:
				break;
		}
		if(choice == 'z')
			if(highlight == 1){
				game = false;
				return game;
			}
			else
				return game;
	}
	return game;
}