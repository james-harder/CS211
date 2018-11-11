#include <iostream>

using namespace std;

// Both parameters have default values in this case
void printCoords(int x = 0, double y = 0);

int main()
{
	printCoords();		// This function call overrides both default values

	return 0;
}

void printCoords(int x, double y)
{
	cout << "(" << x << ", " << y << ")" << endl;
}
