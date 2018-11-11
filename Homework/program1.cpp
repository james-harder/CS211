/*
* NAME:                 James Harder
* WSUID:                s674k343
* HW #:                 labXX
* Description:          The program will ask for a posotive, negative, or zero integer value. If a valid input is received, a menu will display a list
*                       of possible operations. Once an operation is chosen, the program will ask for a second integer, and perform the operation on 
*                       the two operands. If a 0 is given for the second operand of a division operation, the program will display an error message. 
*                       The program will also display an error if the user attempts to raise a number to a negative exponent.
*
*
*/

#include <iostream>

using namespace std;

//Asks the user to input an integer. Place indicates whether this is the first or second input
int getNumber(string place);

int main(void){
    //declare variables for input and operation
    int first = 0, second = 0, operation = 0;
    //declare a variable to indicate valid operation choose
    bool isOp = true;
    //Enter the first number
    first = getNumber("first");

    //Enter the second number
    second = getNumber("second");

    //Choose an operation:
    cout << "Please choose an operation: \n";
    cout << "\t1) Addition\n";
    cout << "\t2) Subtraction\n";
    cout << "\t3) Multiplication\n";
    cout << "\t4) Division\n";
    cout << "\t5) Raise first number to the power of the second\n";
    cout << "Pleasae choose an operation: " << endl;
    cin >> operation;

    //Print the operation menus and loop until valid operation is chosen
    do{
        //Perform the operation and check for errors on division / exponentiation
        case(operation){
            switch(1):
                cout << first << " + " << second << " = " << first + second;
                break;
            switch(2):
                cout << first << " + " << second << " = " << first + second;
                break;
            switch(3):
                cout << first << " + " << second << " = " << first + second;
                break;
            switch(4):
                cout << first << " + " << second << " = " << first + second;
                break;
            switch(5):
                cout << first << " + " << second << " = " << first + second;
                break;
            default:
                cout << "Sorry, that is an invalid choice.";
                isOp = false;
        }
    }while(!isOp)

    return 0;
}

int getNumber(string place){
    
    return 1;
}