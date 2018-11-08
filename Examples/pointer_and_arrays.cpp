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

using namespace std;

int main(void){
	
    int q = 24;                 //declare an int
    int * p = &q;               //declare a pointer to int
    int a[3] = {1,2,4};         //declare an int array of three elements

    //print value of all variables
    cout << p << endl;          //prints memory address
    cout << q << endl;          //prints 24
    cout << &q << endl;         //prints memory address
    cout << *p << endl;         //prints 24
    
    cout << a << endl;          //pritns memory address
    p = a;
    
    cout << *p << *p + 1 << *p + 2 << endl; //prints value of each element in array
    
    //
    // Arrays are pointers
    //
    int arr[10] = {0};
    for(int i : arr){
        cout << i <<  " ";
    }
    for(int i = 0; i < 10; i++){
        arr[i]++;
    }
    cout << *arr << endl;
	return 0;	
}
