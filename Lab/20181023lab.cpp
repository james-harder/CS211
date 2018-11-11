/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			lab10
* Description:	Simulates the rolling of an a arbitrary number d6 dies. The number of dies is input by the user. 
*
*
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(void){
    // seed random function
    srand(time(0));

	//ask how many dies the user wants to roll, assign it to a variable
    int numberOfDies = 0;
    cout << "How many dice would you like to roll?";
    cin >> numberOfDies;

    //dynamically create an array of the appropriate size
    int *dies = new int[numberOfDies];

    // loop through each element of the array and assign a random number from 1 to 6
    // then print the array contents on a single line
    for(int i = 0; i < numberOfDies; i++){
        dies[i] = rand() % 6 + 1;
        cout << dies[i];
    }
    cout << endl;
    
    // return the memory and get rid of the pointer
    delete [] dies;
    dies = nullptr;
    
	return 0;	
}
