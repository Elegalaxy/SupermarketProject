#include <iostream>
#include "Terminal.h"
#include <ncurses.h>
#include <string>
using namespace std;

int main(){
	Terminal terminal;
	int y,x;
	getmaxyx(stdscr, y, x);
	cout << y << " " << x;
	cin >> y;
	return 0;
}