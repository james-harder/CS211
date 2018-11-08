#include <iostream>

using namespace std;

int main(void) {
 double price = 78.50;

 cout.setf(ios::fixed);
 cout.setf(ios::showpoint);
 cout.precision(2);
 
 cout << "Your price is $" << price << endl;

 return 0;
}
