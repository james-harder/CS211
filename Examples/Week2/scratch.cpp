/*
 * Name: Adam Sweeney
 * WSUID: a111a111
 * HW: 
 * Description: 
 */

#include <iostream>

using namespace std;

int main()
{
    int input;

    do {
        cout << "Which pet is the best pet of all the pets?\n"
            << "\t1. Cat\n"
            << "\t2. Hamster\n"
            << "\t3. Dog\n";
        cout << "Please enter the number of your choice: ";
        cin >> input;

        cout << "You have chosen...";
        if (input == 3)
            cout << "wisely.\n";
        else
            cout << "poorly.\n";
    } while (input != 3);

    return 0;
}