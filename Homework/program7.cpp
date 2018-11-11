/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			HW07
* Description:	Sort an array of words input by user.
*
*
*/

// A Template for class submissions - CS211
// N.B. address for uploading assignments:
// cslab-sftp.cs.wichita.edu

#include <iostream>
#include <string>

using namespace std;
using std::string;

const int NUM_WORDS = 10;

int getList(string arr[], const int size);
void bubbleSort(string arr[], const int size);
void printArray(string arr[], const int size);
void swapElement(string arr[], const int ind1, const int ind2);

int main(void){
    string words[NUM_WORDS];
	int listSize = 0;

	listSize = getList(words, NUM_WORDS);
	
    bubbleSort(words, listSize);
	
    printArray(words, listSize);
	
	return 0;	
}

int getList(string arr[], const int size){
	string word;
	int i = 0;
	for(; i < size; i++){
        cout << "Please enter a word: ";
        cin >> word;
        if(word == "0"){
            return i;
        }else{
            arr[i] = word;
        }
    }
	
	return i;
}

void bubbleSort(string arr[], const int size){
	bool swap = true;

	while(swap){    						    // if flag is set to false, no changes were made
		swap = false;						    // assume array is in order
		for(int i = 1; i < size; i++){		    // loop through array
			if(arr[i].compare(arr[i-1]) < 0){	// if elements are out of order
				swapElement(arr, i-1, i);	    // swap elements
				swap = true;				    // set flag so loop repeats
			}
		}
	}

	return;
}

void printArray(string arr[], const int size){

	for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return;
}

void swapElement(string arr[], const int ind1, const int ind2){
    
	string temp = arr[ind1];
	arr[ind1] = arr[ind2];
	arr[ind2] = temp;

	return;
}