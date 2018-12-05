/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			HW10
* Description:	Converts a zipcode between postnet and decimal formats, saving result in a text file.
*
*
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Zipcode {
	int romanZipcode;
	string postnetCode;	// does NOT store the leading and trailing 1
						// EX: '  || |  |  ||  |   |'
};

// accepts both roman and barcode formats
// fills both struct members
Zipcode fillZipcode(const string zip);

// converts roman to barcode
string romanToPOSTNET(const int r);

// converts barcode to roman
int postnetToRoman(const string p);

void printRomanZip(const Zipcode zip);
void printPOSTNET(const Zipcode zip);

// filename will be the roman zipcode
// contents will be the graphical barcode
void writeToFile(const Zipcode zip);

// Get user input and call appropriate functions
void processZip(int prompt);

int main(void){	
	int mainMenu;

	cout << "This program is able to convert zip codes to a "
		 << "POSTNET format and vice versa\n"
		 << "\t1. Convert zip code to POSTNET\n"
		 << "\t2. Convert POSTNET to zip code\n"
		 << "\t3. Quit\n";

	do {
		cout << "Pleaase make your selection: ";
		cin >> mainMenu;

		switch(mainMenu) {
			case 1:
			case 2:
				processZip(mainMenu);
				break;
			default:
				if(mainMenu != 3) {
					cout << "Invalid choice...\n";
				} else {
					cout << "\n";
				}
		}
	} while (mainMenu != 3);
	
	return 0;	
}

Zipcode fillZipcode(const string zip) {
	// create new Zipcode object
	// check length of zip to determine roman/postnet
	// save in appropiate variable
	// convert and save in other variable
	// return Zipcode object
	struct Zipcode z { 67276, " ||  |   |  | ||   | ||  "};
	return z;
}

string romanToPOSTNET(const int r) {
	// this is going to take some thought
	// for now, just return a string:
	return string(" ||  |   |  | ||   | ||  ");
}

int postnetToRoman(const string p) {
	// the encoded string, since the second row is always the same, it can be 
    // created programmatically
    //string p = "|   | |     |       |     |   |   | |     | |       |";

    // binary version of p, with leading and trailing pipes removed
    string b = "";
    for(int i = 2; i <= 50; i += 2) {
        if(p.at(i) == '|') {
            b += "|";
        } else {
            b += " ";
        }
    }

    int pKey[5] = {7, 4, 2, 1, 0};                      // the list of values for translating postnet
    string roman = "";                                  // the roman version of the zipcode
    int digitSum = 0;                                   // holds the sum of each five number set
    for(int i = 0; i < 25; i++) {
        if((i+1) % 5 == 0) {                            // matches the value of pKey to the index of the current character
            if(digitSum == 11) {
                roman.append("0");
            } else {
                roman.append(to_string(digitSum));
            }
            
            digitSum = 0;
        } else if(b.at(i) == '|') {
            digitSum += pKey[i % 5];
        }
    }
	
    cout << roman << endl;

    // print out postnet barcode
    cout << p << '\n';
    for(int i = 0; i < 26; i++) {
        cout << "| ";
    }
    cout << "|" << endl;

	return stoi(roman);
}

void printRomanZip(const Zipcode zip) {

	return;
}

void printPOSTNET(const Zipcode zip) {

	return;
}

void writeToFile(const Zipcode zip) {

	return;
}

void processZip(int prompt) {
	// ask user for zipcode (roman if prompt == 1)
	cout << "Enter a Zip code in " << ((prompt == 1) ? "Roman format (#####):" : "Bar-Code format (1's and 0's):");
	string z;
	cin >> z;
	(if z.size() != 5 || z.size() != 25) {
		cout << "Sorry, invalid input." << endl;
		return;
	}

	cout << z << endl;
	// pass string to fillZipCode and create a Zipcode object from the returned object
	Zipcode zip = fillZipcode(z);
	
	// print roman zipcode
	// print graph 
	// save graph
	return;
}