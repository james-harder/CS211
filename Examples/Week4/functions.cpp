#include <iostream>

using namespace std;

double min(double a, double b);

int main()
{
    double firstEntry;
    double secondEntry;
    cout << "Enter a number: ";
    cin >> firstEntry;
    cout << "Enter anohter number: ";
    cin >> secondEntry;

    double result = min(firstEntry, secondEntry);

    cout << "The smaller number was: " << result << endl;

    return 0;
}

double min(double a, double b)
{
    if (a < b)
        return a;
    else
        return b;
}