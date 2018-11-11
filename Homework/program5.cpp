/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			HW05
* Description:	Print the complete lyrics to BINGO. 
*
*
*/

#include <iostream>
#include <cstring>

using namespace std;

// Declare const size and char array 
const int SIZE = 5;
const char dog[SIZE] = {'B', 'I', 'N', 'G', 'O'};

// prints bingo with correct capitalization and/or blanks
void bingo(char const *output, int cap, int blanks);

int main(void){
    // format double outputs
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //print the verse 6 times 
	for(int i = 0; i <= SIZE; i++){
        // output lyrics
		cout << "There was a farmer had a dog\nand ";
        bingo(dog, SIZE, 6);                            // calls bingo() to print "Bingo"
		cout << " was his name-o\n";
        bingo(dog, SIZE, i);                            // calls bingo() to print name with appropriate blanks three times
		cout << "And ";
        bingo(dog, SIZE, 6);                            // calls bingo() to print "Bingo"
		cout << " was his name-o\n" << endl;
	}	

	return 0;	
}

// name is a pointer to the const array to print.
// cap is the capacity of the array
// blanks is the number of letters to blank out, starts at the beginning of the string
//      -If blanks is larger than cap, prints string capitalized, just once.
// returns nothing.
void bingo(char const *name, int cap, int blanks){
    // checks for valid input to blanks
    if(blanks < 0){
        return;
    }

    if(blanks > cap){
        cout << (char)toupper(name[0]);
        for(int i = 1; i < cap; i++){
            // c = tolower(name[i]);
            // cout << c;
            cout << (char)tolower(name[i]);
        }
        return;
    }else{
        for(int j = 0; j < 3; j++){
            for(int i = 0; i < blanks; i++){
                cout << "* ";
            }
            for(int j = blanks; j <= cap; j++){
                cout << (char)toupper(name[j]) << " ";
            }
            cout << endl;
        }
        return;
    }
}