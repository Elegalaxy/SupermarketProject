#include "Terminal.h"
#include <ncurses.h>
#include <string>
using namespace std;

bool menu(){
	Terminal terminal;
	int y, x, yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	WINDOW * menu = terminal.createWin(10, 20, (yMax/2)-5, (xMax/2)-10);
	bool game = true;

	string choices[2] = {"Start", "Quit"};
	int choice;
	int highlight = 0;
	
	while(game){
		for(int i = 0; i < 2; i++){
			if(i == highlight)
				wattron(menu, A_REVERSE);
			mvwprintw(menu, i+4, 7, choices[i].c_str());
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
		if(choice == 10)
			if(highlight == 1){
				game = false;
				return game;
			}
			else
				return game;
	}
	return game;
}