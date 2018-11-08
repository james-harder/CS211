#include <iostream>

using namespace std;

int main(void){

    // Let's declare some variables and pointer variables
    int x = 1, y = 2, z = 3;
    int *xPtr = &x, *yPtr = &y, *zPtr = &z;

    // Let's output some stuff 
    cout << xPtr << endl;       // print the address of x
    cout << x << endl;          // print the value of x
    cout << *xPtr << endl;      // print the value of x via xPtr
    cout << yPtr << endl;       
    cout << y << endl;
    cout << zPtr << endl;
    cout << z << endl;

    // Let's change some things
    *xPtr = z;                  // changes value of x to zPtr
    cout << "x now is: " << x << endl;

    // Let's use some heap memory!!!
    int *heapPtr = new int;     // heapPtr now points to some int space in the heap 
                                // this memory has no variable name, and can only be
                                // accessed through *heapPtr 
    delete heapPtr;             // The memory has now been returned to the heap, but
                                // that's not enough!!!
    heapPtr = nullptr;          // Now, the pointer is no longer a "dangling pointer"


    return 0;
}