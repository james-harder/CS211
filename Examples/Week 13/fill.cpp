#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	char oldFill = cout.fill('.');	// The function fill returns the previous fill character
	cout << "Adam Sweeney" << setw(25) << "(555)555-5555";
	cout << endl;

	cout.fill(oldFill);				// Resetting fill back to the default
	return 0;
}
