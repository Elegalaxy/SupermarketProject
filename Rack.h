#ifndef Rack_H
#define Rack_H
#include "Draw.h"
#include ""
#include <string>
#include <vector>

class Rack{
	private:
		static int rackID;
		int currentID;
		std:vector<std:string> items;
	
	public:
		Rack(){
			currentID = rackID;
		}
		
		int getID(){
			return currentID;
		}
		
		void setRack(std:vector<std:string> vec){
			items = vec;
		}
};
#endif