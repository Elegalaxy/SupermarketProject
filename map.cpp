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
	vector<vector<Rack>> *rackList = new vector<vector<Rack>>;
	vector<Rack> tempRack;
	
	//products
	vector<vector<Product>> *products = new vector<vector<Product>>;
	vector<Product> proTemp;
	string line;
	ifstream fin("test.txt");
	while(getline(fin, line)){
		Product *p = new Product(line);
		proTemp.push_back(*p);
		if(proTemp.size() == 8){
			products->push_back(proTemp);
			proTemp.clear();
		}
		
	}

	fin.close();

	/*vector<Product> testProducts;
	Product p1("Food1");
	Product p2("Food2");
	Product p3("Food3");
	Product p4("Food4");
	Product p5("Food5");
	Product p6("Food6");
	Product p7("Food7");
	Product p8("Food8");
	testProducts.push_back(p1);
	testProducts.push_back(p2);
	testProducts.push_back(p3);
	testProducts.push_back(p4);
	testProducts.push_back(p5);
	testProducts.push_back(p6);
	testProducts.push_back(p7);
	testProducts.push_back(p8);*/
	
	//racks1	
	Rack *rack11 = new Rack(map, rackY, rackX, startY, startX, /*testProducts);*/&(*products)[0]);
	tempRack.push_back(*rack11);
	delete(rack11);
	
	Rack *rack12 = new Rack(map, rackY, rackX, startY, rack11->getLocation('x') + rack11->getSize('x'), /*testProducts);*/&(*products)[1]);
	tempRack.push_back(*rack12);
	delete(rack12);

	Rack *rack13 = new Rack(map, rackY, rackX, startY, rack12->getLocation('x') + rack12->getSize('x') + startX, /*testProducts);*/&(*products)[2]);
	tempRack.push_back(*rack13);
	delete(rack13);
	
	Rack *rack14 = new Rack(map, rackY, rackX, startY, rack13->getLocation('x') + rack13->getSize('x'), /*testProducts);*/&(*products)[3]);
	tempRack.push_back(*rack14);
	delete(rack14);

	Rack *rack15 = new Rack(map, rackY, rackX, startY, rack14->getLocation('x') + rack14->getSize('x') + startX, /*testProducts);*/&(*products)[4]);
	tempRack.push_back(*rack15);
	delete(rack15);

	Rack *rack16 = new Rack(map, rackY, rackX, startY, rack15->getLocation('x') + rack15->getSize('x'), /*testProducts);*/&(*products)[5]);
	tempRack.push_back(*rack16);
	delete(rack16);

	rackList->push_back(tempRack);
	tempRack.clear();
	
	//racks2
	startY = rack11->getLocation('y') + rack11->getSize('y') + 3;
			
	
	Rack *rack21 = new Rack(map, rackY, rackX, startY, startX, /*testProducts);*/&(*products)[6]);
	tempRack.push_back(*rack21);
	delete(rack21);

	Rack *rack22 = new Rack(map, rackY, rackX, startY, rack21->getLocation('x') + rack21->getSize('x'), /*testProducts);*/&(*products)[7]);
	tempRack.push_back(*rack22);
	delete(rack22);
	
	Rack *rack23 = new Rack(map, rackY, rackX, startY, rack22->getLocation('x') + rack22->getSize('x') + startX, /*testProducts);*/&(*products)[8]);
	tempRack.push_back(*rack23);
	delete(rack23);
	
	Rack *rack24 = new Rack(map, rackY, rackX, startY, rack23->getLocation('x') + rack23->getSize('x'), /*testProducts);*/&(*products)[9]);
	tempRack.push_back(*rack24);
	delete(rack24);
	
	Rack *rack25 = new Rack(map, rackY, rackX, startY, rack24->getLocation('x') + rack24->getSize('x') + startX, /*testProducts);*/&(*products)[10]);
	tempRack.push_back(*rack25);
	delete(rack25);
	
	Rack *rack26 = new Rack(map, rackY, rackX, startY, rack25->getLocation('x') + rack25->getSize('x'), /*testProducts);*/&(*products)[11]);
	tempRack.push_back(*rack26);
	delete(rack26);

	rackList->push_back(tempRack);	
	tempRack.clear();
			
	//counter
	Counter *counter = new Counter(map, 2, 9, yMax - 5, 1, &(*rackList));
	
	//recycle bin
	Bin *bin = new Bin(map, 3, 5, yMax-6, xMax-10);
	
	//player
	Player * p = new Player(map, yMax-7, 4, '@', &(*rackList), *counter, *bin, &game);
	do {
		p->display();
		wrefresh(map);
	}while(p->getmv() != 'q' && game == true);
	sleep(3);
	return 0;
}