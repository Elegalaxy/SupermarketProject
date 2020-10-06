#ifndef Draw_H
#define Draw_H
#include <ncurses.h>

void drawBox(WINDOW * win, int y, int x, int yStart, int xStart){
	int yEnd = yStart + y;
	int xEnd = xStart + x;
	
	for(int i = yStart; i < yEnd; i++){
		for(int j = xStart; j < xEnd; j++){
			if(i == yStart || i == yEnd-1){
				mvwaddch(win, i, j, '=');
			}else if(j == xStart || j == xEnd-1){
				mvwaddch(win, i, j, '|');
			}
		}
	}
}

#endif