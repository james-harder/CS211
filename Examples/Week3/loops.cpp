#include <iostream>

using namespace std;

int main(void)
{
    // First, a while loop
    cout << "WHILE LOOP\n";
    int count = 1;
    while (count <= 10) {
        cout << "I have " << count << " jelly bean";
        if (count > 1) {
            cout << "s.\n";
        } else {
            cout << ".\n";
        }
        count++;
    }

    // Second, a do-while loop
    cout << "\n\nDO-WHILE LOOP\n";
    count = 1;  // Generally frowned upon, better to use a new variable
    do {
        cout << "I have " << count << " jelly bean";
        if (count > 1) {
            cout << "s.\n";
        } else {
            cout << ".\n";
        }
        // count++;
    } while(count++ <= 10);

    // Finally, a for loop
    cout << "\n\nFOR LOOP\n";
    for (int i = 1; i <= 10; i++) {
        cout << "I have " << i << " jelly bean";
        if (i > 1) {
            cout << "s.\n";
        } else {
            cout << ".\n";
        }
    }

    return 0;
}
