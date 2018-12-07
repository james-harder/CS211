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

const int pKey[5] = {7, 4, 2, 1, 0};                      // the list of values for translating postnet

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

// convert 1's and 0's to graphical barcode
string postnetToBarcode(const Zipcode zip);

int main() {	
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
	string p;
	int r;

	if( zip.size() == 5 ) {
		r = stoi(zip);
		p = romanToPOSTNET(r);
	} else {
		p = zip;
		r = postnetToRoman(p);
	}
	
	struct Zipcode z { .romanZipcode = r, .postnetCode = p };

	cout << "\nYour zip code is ";
	printRomanZip(z);
	cout << ", and the barcode looks like this:\n\n";
	printPOSTNET(z);
	cout << endl;

	return z;
}

string romanToPOSTNET(const int r) {
	string p;
	string roman = to_string(r);
	for(int i = 0; i < 5; i++) {
        int hits = 0;
		int digit = roman.at(i) - '0';
        if(digit != 0) {
            for(int j = 0; j < 5; j++) {                
                if(digit >= pKey[j] && hits < 2) {
                    p.append("1");
                    digit -= pKey[j];
                    hits++;
                } else {
                    p.append("0");
                }
            }
        } else {
            p.append("11000");
        }
	}
    return p;
}


int postnetToRoman(const string p) {
    string roman = "";                                  // the roman version of the zipcode
    int digitSum = 0;                                   // holds the sum of each five number set
	int hits = 0;
    for(int i = 0; i < 25; i++) {
        if((i+1) % 5 == 0) {                            // matches the value of pKey to the index of the current character
            if(digitSum == 11) {
                roman.append("0");
            } else {
                roman.append(to_string(digitSum));
            }
            digitSum = 0;
        } else if(p.at(i) == '1') {
            digitSum += pKey[i % 5];
			hits += 1;
			if(hits > 2) {
				cerr << "There was a problem with the Postnet number entered." << endl;
				exit(1);
			}
        }
    }

	return stoi(roman);
}

void printRomanZip(const Zipcode zip) {
	cout << zip.romanZipcode;

	return;
}

void printPOSTNET(const Zipcode zip) {
	cout << postnetToBarcode(zip);
	return;
}

void writeToFile(const Zipcode zip) {
	string fileData = postnetToBarcode(zip);
	string fileName = to_string(zip.romanZipcode) + ".txt";
	ofstream zipFile(fileName, ofstream::out);

	if(!zipFile.fail()) {
		zipFile << fileData;
		zipFile.close();
	}
	cout << "Your zip code was saved in the file: " << fileName;
	return;
}

void processZip(int prompt) {
	// ask user for zipcode (roman if prompt == 1)
	cout << "\nEnter a Zip code in " << ((prompt == 1) ? "Roman format (#####):" : "Bar-Code format (1's and 0's):");
	string z;
	cin >> z;
	if( z.size() != 5 && z.size() != 25 ) {
		cout << "Sorry, " << z.size() << " is invalid input." << endl;
		return;
	}

	// pass string to fillZipCode and create a Zipcode object from the returned object
	Zipcode zip = fillZipcode(z);
	cout << endl;

	writeToFile(zip);
	cout << '\n' << endl;

	return;
}

string postnetToBarcode(const Zipcode zip) {
	string barcode = "|";
	for( auto i : zip.postnetCode) {
		i == '1' ? barcode.append("|") : barcode.append(" ");
	}
	barcode.append("|\n");
	for(int i = 0; i < 27; i++) {
		barcode.append("|");
	}

	return barcode;
}