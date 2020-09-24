#include <iostream>
#include "Product.h"
using namespace std;

int main(){
	Product *p = new Product("Chicken");
	
	cout << p->getName() << endl;
	return 0;
}