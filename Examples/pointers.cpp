#include <iostream>     // No special library needed for pointers
#include <iomanip>

using namespace std;

int main()
{
    double pi = 3.14159;
    double *ptr;

    ptr = &pi;

    // This first part of the code illustrates where variables live, and the values they hold
    char prev = cout.fill('.');
    cout << setw(25) << left << "Address of pi"         << &pi << endl;
    cout << setw(25) << left << "Value of pi"           << pi << endl << endl;

    cout << setw(25) << left << "Address of ptr"        << &ptr << endl;
    cout << setw(25) << left << "Value of ptr"          << ptr << endl;
    cout << setw(25) << left << "De-referencing ptr"    << *ptr << endl << endl;



    // This section illustrates how we can use pointers to manipulate variables and vice-versa
    cout << "--- Changing the value through the pointer\n";
    *ptr = 7.2479;
    cout << setw(25) << left << "Address of pi"         << &pi << endl;
    cout << setw(25) << left << "Value of pi"           << pi << endl << endl;

    cout << "--- Changing it back via the original variable\n";
    pi = 3.14159;
    cout << setw(25) << left << "Address of ptr"        << &ptr << endl;
    cout << setw(25) << left << "Value of ptr"          << ptr << endl;
    cout << setw(25) << left << "De-referencing ptr"    << *ptr << endl << endl;



    // This section shows how dynamic variables can be used
    cout << "--- Dynamic Pointer\n";
    double *dynPtr = new double(5.892);

    cout << setw(25) << left << "Address of dynPtr"        << &dynPtr << endl;
    cout << setw(25) << left << "Value of dynPtr"          << dynPtr << endl;
    cout << setw(25) << left << "De-referencing dynPtr"    << *dynPtr << endl << endl;

    delete dynPtr;      // Give dynamically allocated memory back to the heap
    dynPtr = nullptr;   // null pointer to remove dangling pointer value

    cout.fill(prev);

    return 0;
}