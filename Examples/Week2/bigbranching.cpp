/*
 * Name: 
 * WSUID: 
 * HW: 
 * DESCRIPTION: 
 */

#include <iostream>

using namespace std;

int main()
{
    int choice;
    cout << "Enter a number (1 - 4): ";
    cin >> choice;

    if (choice == 1) {
        cout << "One\n";
    } 
    else if (choice == 2) {
        cout << "Two\n";
    } 
    else if (choice == 3) {
        cout << "Three\n";
    } 
    else if (choice == 4) {
        cout << "Four\n";
    } 
    else {
        cout << "Bad Entry\n";
    }

    return 0;
}