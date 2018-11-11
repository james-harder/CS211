#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	// I have to declare file streams
	ifstream fileInput;	// The type is ifstream (input file stream) and the name of the stream is fileInput
	ofstream outFile;	// The type is ofstream (output file stream) and the name of the stream is outFile
	int x, y;

	// Attaching file to my input stream
	// fileInput is the calling object, calling its open() function
	fileInput.open("input.txt");
	if (fileInput.fail()) {	// Checking it opened successfully
		cout << "Error opening file. Exiting...\n";
		exit(1);
	}

	// Attaching file to my output stream
	// outFile is the calling object, calling its open() function
	outFile.open("output.txt");
		if (outFile.fail()) {
			cout << "Error opening file. Exiting...\n";
			exit(1);
		}

	do {
		fileInput >> x;	// Use of an ifstream is just like cin
		fileInput >> y;
		
		outFile << "(" << x << ", " << y << ")" << endl;	// Use of an ofstream is just like cout
	} while( !(fileInput.eof()) );

	// Now that we've finished processing the files, we should close them
	fileInput.close();
	outFile.close();
    
    return 0;
}