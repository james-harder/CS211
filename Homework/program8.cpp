/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			HW08
* Description:	encodes a phrase using squareCode. The coded block should have twelve columns in each row. 
*
*
*/

#include <iostream>

using namespace std;

string sanitizePhrase(string phrase);               // strips white space and punctuation from phrase
string fillPhrase(string phrase);                   // returns a string with that will have the appropiate length for encoding 
string encodePhrase(string phrase, int rows);       // encodes phrase using square code

const string WHITE_SPACE(" \t\n\r.,!?';\"");        // characters to strip from phrase
const int COLS = 12;                                // number of columns in encoded block

int main(void){
	string phrase = "";
    cout << "Please enter a phrase: ";
    getline(cin, phrase);

    phrase = sanitizePhrase(phrase);
    
    phrase = fillPhrase(phrase);
    
    int rows = phrase.size() / COLS;                  // determine the appropiate number of rows based on number of COLS
    phrase = encodePhrase(phrase, rows);

    cout << phrase;

    cout << endl;
    
    return 0;	
}

string sanitizePhrase(string phrase) {
    size_t found = phrase.find_first_of(WHITE_SPACE);       // find the first character to erase
    while(found != string::npos){                           // continues until no characters are found to erase
        phrase.erase(found, 1);                             // erases 1 character found at index 'found'
        found = phrase.find_first_of(WHITE_SPACE);
    }

    return phrase;
}

string fillPhrase(string phrase) {
    int numFill = COLS - phrase.size() % COLS;              // the number of characters needed to fill
    while( numFill != 0){
        phrase += "#";
        numFill--;
    }

    return phrase;
}

string encodePhrase(string phrase, int rows) {
    string encodedPhrase("");
    string **squareCode = new string*[rows];                
        
    for(int j = 0; j < rows; j++) {                     // loop through string, and every twelfth character go to new row...
        squareCode[j] = new string[COLS];               
        for(int k = 0; k < COLS; k++) {
            int calcIndex = j * COLS + k;               // finds the 12th character and adds k to it so that we are pulling 
            squareCode[j][k] = toupper(phrase[calcIndex]);       // the appropiate character to put in the 2d array     
        }
    }

    // print phrase as a square block
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < COLS; j++) {
            cout << squareCode[i][j] << " ";
        }
        cout << '\n';
    }
    cout << endl;
    
    //loop through 2d array, pull all characters in the same column from each row.
    for(int i = 0; i < COLS; i++) {
        for(int j = 0; j < rows; j++) {
            if(squareCode[j][i] != "#") {
                encodedPhrase += squareCode[j][i];
            }
        }
        encodedPhrase += " ";
    }
    
    return encodedPhrase;
}