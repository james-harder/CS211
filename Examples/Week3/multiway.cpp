#include <iostream>

using namespace std;

int main(void) {
    char grade, gradeCopy;
    cout << "Enter your midterm grade: ";
    cin >> grade;

    switch (grade) {
    case 'A':
        cout << "Excellent! No need to take the final.\n";
        break;
    case 'B':
        gradeCopy = 'A';
        cout << "Very good. Your midterm grade is now " << gradeCopy << endl;
        break;
    case 'C':
        cout << "Passing.\n";
        break;
    case 'D':
    case 'F':
        cout << "Not good. Go study.\n";
        break;
    default:
        cout << "That is not a valid grade.\n";
    }

    cout << "\n\nRunning evaulation again using if-else\n\n\n";

    if (grade == 'A') {
        cout << "Excellent! No need to take the final.\n\n";
    } else if (grade == 'B') {
        gradeCopy = 'A';
        cout << "Very good. Your midterm grade is now " << gradeCopy << endl;
    } else if (grade == 'C') {
        cout << "Passing.\n";
    } else if (grade == 'D' || grade == 'F') {
        cout << "Not good. Go study.\n";
    } else {
        cout << "That is not a valid grade.\n";
    }

  return 0;
}
