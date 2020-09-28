#ifndef Draw_H
#define Draw_H
#include <ncurses.h>

void drawBox(WINDOW * win, int y, int x, int yStart, int xStart){
	int yEnd = y + yStart;
	int xEnd = x + xStart;
	
	for(int i = 2; i < yEnd; i++){
		for(int j = 2; j < xEnd; j++){
			if(i == 2 || i == yEnd-1){
				mvwaddch(win, i, j, '=');
			}else if(j == 2 || j == xEnd-1){
				mvwaddch(win, i, j, '|');
			}
		}
	}
}

#endif