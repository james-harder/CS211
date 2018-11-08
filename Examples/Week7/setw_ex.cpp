#include <iostream>
#include <iomanip>  // setw()

using namespace std;

int main()
{
    char prev = cout.fill('.');

    cout << setw(10) << "Hi" << setw(10) << "Hello" << setw(10) << "Howdy" << endl;

    cout.fill(prev);

    return 0;
}