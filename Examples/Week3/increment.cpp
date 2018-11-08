#include <iostream>

using namespace std;

int main(void) {
	int number = 2;
	int valueProduced = 2 * (number++);
	cout << valueProduced << endl;
	cout << number << endl;
	
	return 0;
}