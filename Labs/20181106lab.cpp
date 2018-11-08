/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			lab11 
* Description:	Asks user for an adjective, and fills in the blank of a sentence. The sentence is
*               then written to a file called 'madlibs.txt' in the current directory.
*
*
*/


#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    
    cout << "Please enter an adjective: ";                  // ask user for an adjective
    std::string adj;                                        // create a string to hold the adjective
    cin >> adj;                                             // read the user input and store in adj 
    // concatenate adj to the end of the sentence and store in sentence
    std::string sentence = "I dont' want to drop this bag, it's too " + adj + ".";
    
    string fn = "madlibs.txt";                              // name of file to write to
    ofstream madFile(fn);                                   // declare an ofstream object named madlib.txt
    if(madFile.fail()){                                     // if the file stream fails to open
        cerr << "Unable to open " << fn << "..." << endl;   // print a statement to standard err
        exit(1);                                            // exit the program on fail to open
    }

    madFile << sentence << endl;                            // write the sentence to the ofstream

    madFile.close();                                        // close the file

	return 0;	
}
