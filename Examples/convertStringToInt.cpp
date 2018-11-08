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

using namespace std;

int main(void){
	std::string word = "";
    std::string::size_type sz;

    cout << "Please enter a word: ";
    cin >> word;

    int number = std::stoi(word, &sz, 10);
    if(number == 1){
        cout << "you got it." << endl;
    }

	return 0;	
}
