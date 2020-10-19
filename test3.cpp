#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<string> vec;
	vec.push_back("10");
	vec.push_back("20");
	vec.push_back("30");
	cout << *find(vec.begin(), vec.end(), "40");
	return 0;
}