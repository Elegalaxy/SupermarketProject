//Please note that this is Windows specific code
#include <iostream>
#include <unistd.h>
using namespace std;

void Say_Hello(){
	cout << "Hello" << endl;
}

int main()
{
    for(;;) 
    {

    Say_Hello();
    // Sleep for 5*1000ms
    sleep(500);

    }
}