#include <ncurses.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Terminal.h"
#include "Player.h"
#include "Product.h"
#include "Rack.h"
#include "Bin.h"
#include "Counter.h"
#include <unistd.h>

using namespace std;

extern bool menu();

int main(){
	Terminal terminal;
	if(!menu()){
		refresh();
		return 0;
	}
	
	//define window
	int yMax = 30, xMax = 120;
	WINDOW * map = terminal.createWin(yMax-2, xMax-2, 1, 1);
	bool game = true;
	//define racks size and start point
	const int rackY = 10;
	const int rackX = 12;
	int startX = 8;
	int startY = 1;
	vector<vector<Rack>> rackList;
	vector<Rack> tempRack;
	
	//products
	vector<vector<Product>> products;
	vector<Product> proTemp;
	string line;
	ifstream fin("test.txt");
	while(getline(fin, line)){
		Product *p = new Product(line);
		proTemp.push_back(*p);
		delete(p);
		if(proTemp.size() == 8){
			products.push_back(proTemp);
			proTemp.clear();
		}
	}
	fin.close();

	//racks1	
	Rack *rack11 = new Rack(map, rackY, rackX, startY, startX, products[0]);
	Rack *rack12 = new Rack(map, rackY, rackX, startY, rack11->getLocation('x') + rack11->getSize('x'), products[1]);
	
	Rack *rack13 = new Rack(map, rackY, rackX, startY, rack12->getLocation('x') + rack12->getSize('x') + startX, products[2]);
	Rack *rack14 = new Rack(map, rackY, rackX, startY, rack13->getLocation('x') + rack13->getSize('x'), products[3]);
	
	Rack *rack15 = new Rack(map, rackY, rackX, startY, rack14->getLocation('x') + rack14->getSize('x') + startX, products[4]);
	Rack *rack16 = new Rack(map, rackY, rackX, startY, rack15->getLocation('x') + rack15->getSize('x'), products[5]);
	tempRack.push_back(*rack11);
	tempRack.push_back(*rack12);
	tempRack.push_back(*rack13);
	tempRack.push_back(*rack14);
	tempRack.push_back(*rack15);
	tempRack.push_back(*rack16);
	rackList.push_back(tempRack);
	tempRack.clear();

		
	//racks2
	startY = rack11->getLocation('y') + rack11->getSize('y') + 3;
			
	
	Rack *rack21 = new Rack(map, rackY, rackX, startY, startX, products[6]);
	Rack *rack22 = new Rack(map, rackY, rackX, startY, rack21->getLocation('x') + rack21->getSize('x'), products[7]);
	
	Rack *rack23 = new Rack(map, rackY, rackX, startY, rack22->getLocation('x') + rack22->getSize('x') + startX, products[8]);
	Rack *rack24 = new Rack(map, rackY, rackX, startY, rack23->getLocation('x') + rack23->getSize('x'), products[9]);
	
	Rack *rack25 = new Rack(map, rackY, rackX, startY, rack24->getLocation('x') + rack24->getSize('x') + startX, products[10]);
	Rack *rack26 = new Rack(map, rackY, rackX, startY, rack25->getLocation('x') + rack25->getSize('x'), products[11]);
	tempRack.push_back(*rack21);
	tempRack.push_back(*rack22);
	tempRack.push_back(*rack23);
	tempRack.push_back(*rack24);
	tempRack.push_back(*rack25);
	tempRack.push_back(*rack26);
	rackList.push_back(tempRack);	
	tempRack.clear();
			
	//counter
	Counter *counter = new Counter(map, 2, 9, yMax - 5, 1, rackList);
	
	//recycle bin
	Bin *bin = new Bin(map, 3, 5, yMax-6, xMax-10);
	
	//player
	Player * p = new Player(map, yMax-7, 4, '@', rackList, *counter, *bin, &game);
	do {
		p->display();
		wrefresh(map);
	}while(p->getmv() != 'q' && game == true);
	sleep(3);
	return 0;
}