#include <iostream>

using namespace std;

int factorial(int n);
// You may want to try and figure out an iterative version of this function

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << number << "! = " << factorial(number) << endl;

    return 0;
}

int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return (n * factorial(n - 1));
}