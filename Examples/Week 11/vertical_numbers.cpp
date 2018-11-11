#include <cmath>
#include <iostream>

using namespace std;

void writeVerticalRec(int n);
void writeVerticalIt(int n);

// We want to print a number vertically
int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    writeVerticalRec(number);
    cout << "\n\n";
    writeVerticalIt(number);

    return 0;
}

// This is the recursive function
void writeVerticalRec(int n)
{
    if (n < 10) {
        cout << n << endl;
    }
    else {
        writeVerticalRec(n / 10);
        cout << (n % 10) << endl;
    }
}

// This is the iterative function
void writeVerticalIt(int n)
{
    int power = 1;
    int copy = n;

    while (copy > 9) {
        copy /= 10;
        power *= 10;
    }

    for ( ; power > 0; power /= 10) {
        cout << (n / power) << endl;
        n %= power;
    }
}