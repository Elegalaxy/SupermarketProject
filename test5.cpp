#include <iostream>
using namespace std;

int main()
{
	int 
	int starty = yLoc-1, startx = xLoc-3;
	int endy = yLoc+3, endx = xLoc+3;
	for(int i = 0; i < endx; i++){
		for(int j = 0; j < endy; j++){
			mvwaddch(curwin, i, j, ' ');
			if(i == 0 || j == 0 || i == endx-1 || j == endy-1){
				mvwaddch(curwin, i, j, '*');
			}
			else if(i == yLoc+1 && j == xLoc-1){
				mvwprintw(curwin, i, j, "%s", "You");
				j+=2;
			}else if(i == yLoc+2 && j == xLoc-1){
				mvwprintw(curwin, i, j, "%s", "Win");
				j+=2;
			}
		}
	}
}