/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			lab07
* Description:	This program creates an array of ten integers, and fills it 
*				with the even numbers from 2 to 20. The program then 
*				outputs the numbers on a single line.
*
*
*/

#include <iostream>

using namespace std;

int main(void){
	const int MAX = 20;		//The range of numbers to fill the array
	const int INTERVAL = 2;	//The interval to skip

	int evenNumbers[MAX / INTERVAL]; 

	for(int i : evenNumbers){
		i = i * 2;
	}

	for(int i : evenNumbers){
		cout << i;
	}

	cout << endl;

	return 0;
}