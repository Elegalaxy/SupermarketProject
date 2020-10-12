#include "Terminal.h"
#include "Player.h"
#include "Rack.h"
#include <ncurses.h>
#include "Product.h"
#include <string>
#include <vector>
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
	
	//products
	vector<Product> products;
	Product p1("a");
	products.push_back(p1);
	Product p2("b");
	products.push_back(p2);
	Product p3("c");
	products.push_back(p3);
	Product p4("d");
	products.push_back(p4);
	Product p5("e");
	products.push_back(p5);
	Product p6("f");
	products.push_back(p6);
	Product p7("g");
	products.push_back(p7);
	Product p8("h");
	products.push_back(p8);
	
	//racks1
	Rack *rack11 = new Rack(map, rackY, rackX, startY, startX, products);
	Rack *rack12 = new Rack(map, rackY, rackX, startY, rack11->getLocation('x') + rack11->getSize('x'), products);
	
	Rack *rack13 = new Rack(map, rackY, rackX, startY, rack12->getLocation('x') + rack12->getSize('x') + startX, products);
	Rack *rack14 = new Rack(map, rackY, rackX, startY, rack13->getLocation('x') + rack13->getSize('x'), products);
	
	Rack *rack15 = new Rack(map, rackY, rackX, startY, rack14->getLocation('x') + rack14->getSize('x') + startX, products);
	Rack *rack16 = new Rack(map, rackY, rackX, startY, rack15->getLocation('x') + rack15->getSize('x'), products);
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
	Rack *rack21 = new Rack(map, rackY, rackX, startY, startX, products);
	Rack *rack22 = new Rack(map, rackY, rackX, startY, rack21->getLocation('x') + rack21->getSize('x'), products);
	
	Rack *rack23 = new Rack(map, rackY, rackX, startY, rack22->getLocation('x') + rack22->getSize('x') + startX, products);
	Rack *rack24 = new Rack(map, rackY, rackX, startY, rack23->getLocation('x') + rack23->getSize('x'), products);
	
	Rack *rack25 = new Rack(map, rackY, rackX, startY, rack24->getLocation('x') + rack24->getSize('x') + startX, products);
	Rack *rack26 = new Rack(map, rackY, rackX, startY, rack25->getLocation('x') + rack25->getSize('x'), products);
	tempRack.push_back(*rack21);
	tempRack.push_back(*rack22);
	tempRack.push_back(*rack23);
	tempRack.push_back(*rack24);
	tempRack.push_back(*rack25);
	tempRack.push_back(*rack26);
	rackList.push_back(tempRack);	
	tempRack.clear();
	
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