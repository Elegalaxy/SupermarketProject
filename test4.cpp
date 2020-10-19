#include <iomanip>
#include <iostream>
#include <unistd.h>
using namespace std;

 int main()
 {
   for (int sec = 10; sec < 11; sec--)
 {
      cout << setw(2) << sec;
      cout.flush();

      sleep(1);
      cout << '\r';
      if (sec == 0)
      {
      cout << "boom" << endl;
      }
      if (sec <1) break;
    }
  }