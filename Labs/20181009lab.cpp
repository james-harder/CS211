/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			Lab09
* Description:	Accepts two names from the user. each name should _beep
*               a full name (both first and last). The program introduce
*               the names. The compares them, and states whether they are 
*               same
*
*
*/

#include <iostream>
#include <cstring>

using namespace std;

void getName(char *name[], int cap);

int main(void){
	// two arrays to hold user input
	char *firstName[41] = {'\0'};
	char *secondName[41] = {'\0'};

	cout << "Please enter the full name of the first person: \n";
	// Get input for firstName
	getName(firstName, 40);

	cout << "Please enter the full name of the second person: \n";
	// get input for secondName
	getName(secondName, 40);

	cout << "Hello, " << firstName << ", have you met " << secondName << "?" << endl;

	if(strncmp(firstName, secondName, 40)){
		cout << "You're different people!" << endl;
	}else{
		cout << "You're the same people!" << endl;
	}

	return 0;
	
}

void getName(char *arr[], int cap){
	
	int index = 0;

	while(true){
		
		char c = ' ';
		cin.get(c);
		if(c == '\n'){
			arr[index] = '\0';
			break;
		}else{
			arr[index] = c;
			index++;
		}

		//out of bounds check
		if(index == cap){
			return;
		}
	}

	return;
}
