#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

// This function actually does the hard work
void makeNeat(istream& in, ostream& out, int prec, int fieldw);

int main()
{
	ifstream fin("raw.dat");	// Input file stream
	if (fin.fail()) {			// If I open a file, I need to make sure I opened it
		cout << "Failed to open input file. Exiting...\n";
		exit(1);
	}

	ofstream fout;				// Output file stream
	fout.open("clean.dat");
	if (fout.fail()) {			// If I open a file, I need to make sure I opened it
		cout << "Failed to open output file. Exiting...\n";
		exit(1);
	}

	makeNeat(fin, fout, 5, 20);

	fin.close();	// If I open a file, 
	fout.close();	// I had better close it

	return 0;
}

/* A note on passing streams to functions
 * 		We are able to pass streams to functions, but there are a couple rules
 * 		- First, we ALWAYS pass the stream by reference
 * 		- Second, the stream should be ready to be used; it should already exist and 
 * 		have a file attached to it in the case of file streams
 * 		- Note the types for the streams, istream and ostream
 * 		- These are the generic types for input streams and output streams, respectively
 * 		- This makes our function more flexible, we can pass a any kind of input or output
 * 		stream, we are not restricted to just a file stream or cin/cout
 */

//uses istream and ostream so that this function can be passed a standard input, file, or other input/outpout stream
void makeNeat(istream& in, ostream& out, int prec, int fieldw)
{
	// num holds each number in the file
	double num;
	// entry acts like an index
	int entry = 1;

	char prev = out.fill('.');				// change fill 
	out.setf(ios::fixed);					// no scientific notation
	out.setf(ios::showpoint);				// enforce decimal point
	out.precision(prec);					// set precision to argument
	
	in >> num;								// read first numebr from file and set num to that value 
	while ( !(in.eof()) ) {					// until the file ends
		out << left << setw(4) << entry 	// set left orientation, width of 4, print entry number 
			<< right << setw(fieldw) 		// set right orientation, width of argument 
			<< showpos << num << endl;		// set showpos, print the number and flush the stream 		entry++;
		out.unsetf(ios::showpos);			// turn off showpos 
		in >> num;							// read in the next number from the file and reloop
	}

	out.fill(prev);							// change fill back to whatever it was
}
