// Name
// WSUID
// HW #
// Description

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(void) {
	srand(time(0));
	int randomNum = rand() % 100 + 1; // Creating random number between 0 and 99 inclusive
	cout << "Psst..." << randomNum << endl;
	double bet;
	int number;
	
	cout << "Feeling lucky? Place a bet: $";
	cin >> bet;
	cout << "Enter a number from 0 - 100: ";
	cin >> number;
	
	// THE IMPORTANT PART
	if (number == randomNum) {
        // Returns bet plus 20% if number guessed is correct
		cout << "You Win!\n";
		bet += (bet * 0.2);
	} else {
        // Takes users money because guess was wrong
		cout << "Tough luck! Try again next time...\n";
		bet = 0;
	}
	// /THE IMPORTANT PART
	cout << "You now have $" << bet << endl;
	
	return 0;
}
