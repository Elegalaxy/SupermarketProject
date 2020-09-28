#include "Terminal.h"
#include "Player.h"
#include <ncurses.h>
#include <string>
using namespace std;

int main(){
	Terminal terminal;
	Player *player;
	WINDOW * win = terminal.createWin(20, 20, 1, 1);
	player = new Player(win, 2, 2, '@');
	int choice;

	do {
		player->display();
		wrefresh(win);
	}while(player->getmv() != 'x');
	
	return 0;
}