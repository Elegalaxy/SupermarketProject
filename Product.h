#ifndef Product_H
#define Product_H
#include <string>

class Product{
	private:
		std::string name;
	
	public:
		Product(){
			name = "";
		}
		
		Product(std::string n){
			name = n;
		}
		
		std::string getName(){
			return name;
		}
		
		~Product();
};
#endif