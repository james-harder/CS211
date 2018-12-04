/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			XXXX
* Description:	XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX 
*
*
*/

// A Template for class submissions - CS211
// N.B. address for uploading assignments:
// cslab-sftp.cs.wichita.edu

#include <iostream>
#include <string>
#

using namespace std;

int main(void){
    // index:   |1|2|3|4|5|
    // value:   |7|4|2|1|0|
    // example POSTNET:
    // |   | |     |       |     |   |   | |     | |       |
    // | | | | | | | | | | | | | | | | | | | | | | | | | | |
    // 1 0 1 1 0 0 1 0 0 0 1 0 0 1 0 1 0 1 1 0 0 1 1 0 0 0 1
    // strip outer 1's and split into groups of five:
    // 01100 10001 00101 01100 11000
    // 74210 74210 74210 74210 74210
    //  42   7   0   2 0  42   74
    // 6     7     2     6     11 (0)
    // 67260

    // length of string: 25 characters, plus a space for each = 50
    // plus one character and one space at the beginning, and one character at the end = 53
    // times two rows = 106. Only the first half matter, and of those only 2 through 50, and
    // only the even ones at that. So, 2,4,6,...,50

    // the encoded string, since the second row is always the same, it can be 
    // created programmatically
    string p = "|   | |     |       |     |   |   | |     | |       |";

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
	return 0;	
}
