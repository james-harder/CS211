
#include <iostream>
#include "Money.hpp"

using namespace std;

int main()
{
	Money one, two(3, 50), three(-2.24);

	cout << "I have " << one << ", you have " << two << ", and they have " << three << endl;

	cout << "Combined, you both have ";
	Money sum = two.add(three);
	//Money sum = two + three;
	//sum.print();
	cout << sum << endl;
	//cout << endl;

	Money four = 8.50;
	cout << "Now someone has ";
	// four.print();
	// cout << endl;
	cout << four << endl;

	one = four;
	cout << "Now I am the one who has ";
	// one.print();
	// cout << endl;
	cout << one << endl;

	return 0;
}