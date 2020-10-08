#include <iostream>
#include "Product.h"
#include <string>
using namespace std;

Product::Product(){
	name = "";
}

Product::Product(string n){
	name = n;
}

string Product::getName(){
	return name;
}

Product::~Product(){
	
}
