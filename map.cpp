#include "Terminal.h"
#include "Player.h"
#include "Rack.h"
#include <ncurses.h>
#include <string>
using namespace std;

extern bool menu();

int main(){
	Terminal terminal;
	if(!menu()){
		refresh();
		return 0;
	}
	
	//define window
	int y, x, yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);//30 120
	y = (yMax-30)/2;
	x = (xMax-118)/2;
	WINDOW * map = terminal.createWin(30, 120, y, x);

	//define racks size and start point
	int rackY = 10;
	const int rackX = 10;
	int startX = 8;
	int startY = 1;
	vector<vector<Rack>> rackList;
	vector<Rack> tempRack;
	
	//racks1
	Rack *rack11 = new Rack(map, rackY, rackX, startY, startX);
	Rack *rack12 = new Rack(map, rackY, rackX, startY, rack11->getLocation('x') + rack11->getSize('x'));
	
	Rack *rack13 = new Rack(map, rackY, rackX, startY, rack12->getLocation('x') + rack12->getSize('x') + startX);
	Rack *rack14 = new Rack(map, rackY, rackX, startY, rack13->getLocation('x') + rack13->getSize('x'));
	
	Rack *rack15 = new Rack(map, rackY, rackX, startY, rack14->getLocation('x') + rack14->getSize('x') + startX);
	Rack *rack16 = new Rack(map, rackY, rackX, startY, rack15->getLocation('x') + rack15->getSize('x'));
	tempRack.push_back(*rack11);
	tempRack.push_back(*rack12);
	tempRack.push_back(*rack13);
	tempRack.push_back(*rack14);
	tempRack.push_back(*rack15);
	tempRack.push_back(*rack16);
	rackList.push_back(tempRack);
	tempRack.clear();
	//Rack *rack17 = new Rack(map, rackY, rackX, startY, rack16->getLocation('x') + rack16->getSize('x') + startX);
	//Rack *rack18 = new Rack(map, rackY, rackX, startY, rack17->getLocation('x') + rack17->getSize('x'));
	
	startY = rack11->getLocation('y') + rack11->getSize('y') + 3;
	//racks2
	Rack *rack21 = new Rack(map, rackY, rackX, startY, startX);
	Rack *rack22 = new Rack(map, rackY, rackX, startY, rack21->getLocation('x') + rack21->getSize('x'));
	
	Rack *rack23 = new Rack(map, rackY, rackX, startY, rack22->getLocation('x') + rack22->getSize('x') + startX);
	Rack *rack24 = new Rack(map, rackY, rackX, startY, rack23->getLocation('x') + rack23->getSize('x'));
	
	Rack *rack25 = new Rack(map, rackY, rackX, startY, rack24->getLocation('x') + rack24->getSize('x') + startX);
	Rack *rack26 = new Rack(map, rackY, rackX, startY, rack25->getLocation('x') + rack25->getSize('x'));
	tempRack.push_back(*rack21);
	tempRack.push_back(*rack22);
	tempRack.push_back(*rack23);
	tempRack.push_back(*rack24);
	tempRack.push_back(*rack25);
	tempRack.push_back(*rack26);
	rackList.push_back(tempRack);	
	//Rack *rack27 = new Rack(map, rackY, rackX, startY, rack26->getLocation('x') + rack26->getSize('x') + startX);
	//Rack *rack28 = new Rack(map, rackY, rackX, startY, rack27->getLocation('x') + rack27->getSize('x'));
	
	//counter
	
	
	//recycle bin
	
	
	//player
	Player * p = new Player(map, y+24, 4, '@', rackList);
	do {
		p->display();
		wrefresh(map);
	}while(p->getmv() != 'x');
	
	return 0;
}