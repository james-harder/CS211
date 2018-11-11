/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			HW04
* Description:	A virtual vending machine
*
*
*/

#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

// lists snacks available and prompts user for choice
int menu();

// prompts user to choose coins until price is met
int acceptMoney(int price);

// returns the proper change to the user
int computeChange(int totalPaid, int totalDue);

int main(void){
    bool wantsAnotherSnack = true;
    char choice = 'N';
    int totalPrice = 0, totalPaid = 0, change = 0;

    //introduction
    cout << "Welcome to the snack machine" << endl;

    //display menu as long as user wants another snack 
    while(wantsAnotherSnack){
        //call the menu
        totalPrice += menu();

        //call the acceptMoney
        totalPaid = acceptMoney(totalPrice);

        //call computeChange
        change = computeChange(totalPaid, totalPrice);
 
        //display cost of chosen snack, total paid, and change dispensed
        cout << "Your total amount paid:" << totalPaid << endl;
        cout << "Dispensing change" << change << endl;

        //ask if user wants another snack 
        cout << "Would you like another snack? (Y/N):";
        cin >> choice;

        if(toupper(choice) != 'Y'){
            wantsAnotherSnack = false;
        }
    }
	
	return 0;
	
}

int menu(){
    bool isValid = false;
    char choice = ' ';
    int price = 0;
    while(!isValid){
        //display menu and prompt for choice
        cout << "Available snacks to select from:\n";
        cout << "\tP - Potato Chips\t$1.25\n";
        cout << "\tS - Snickers Bar\t$1.35\n";
        cout << "\tT - Pop Tart\t\t$0.95\n";
        cout << "\tC - Cookies\t\t$1.50\n";
        cout << "\tB - Brownie\t\t$1.75\n";
        cout << "\tN - Nuts\t\t$1.40\n";
        cout << "Please enter the letter labeling your snack selection: ";
        cin >> choice;
        choice = toupper(choice);

        //set isValid true if choice is valid
        isValid = true;

        switch(choice){
            case 'P':
                price = 125;
                break;
            case 'S':
                price = 135;
                break;
            case 'T':
                price = 95;
                break;
            case 'C':
                price = 150;
                break;
            case 'B':
                price = 175;
                break;
            case 'N':
                price = 140;
                break;
            default: 
                isValid = false;
                break;
        }
    }

    return price;
}

int acceptMoney(int totalPrice){
    int totalPaid = 0;
    char choice = ' ';

    while(totalPaid < totalPrice){
        //ask user to insert coins
        cout << "Money accepted by the machine:\n";
        cout << "\tN - Nickel\n";
        cout << "\tQ - Quarter\n";
        cout << "\tD - Dollar\n";
        cout << setw(32) << "your selected snack item cost:" << totalPrice << endl;
        cout << setw(32) << "Your total inserted amount:" << totalPaid << endl;
        cout << "please enter your choice of coin: ";
        cin >> choice;
        choice = toupper(choice);

        switch(choice){
            case 'N':
                totalPaid += 5;
                break;
            case 'Q':
                totalPaid += 25;
                break;
            case 'D': 
                totalPaid += 100;
                break;
            default:
                cout << choice << " is not recognized as a coin" << endl;
        }
        
    }

    return totalPaid;
}

int computeChange(int totalPaid, int totalPrice){
    return totalPaid - totalPrice;
}