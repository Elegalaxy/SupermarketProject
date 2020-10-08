#ifndef Product_H
#define Product_H
#include <string>

class Product{
	private:
		std::string name;
	
	public:
		Product();
		Product(std::string n); //initialize name
		std::string getName(); //return name
		~Product();
};
#endif