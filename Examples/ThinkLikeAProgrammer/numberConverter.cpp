#include <iostream>
#include <vector>

using namespace std;
using std::vector;

// convert a char to its integer value
int charToInt(char letter);

int binToDec();
int hexToDec();

int main(){
    cout << hexToDec() << endl;
    
    return 0;
}

int charToInt(char letter) {
    // convert to uppercase for hex numbers
    letter = toupper(letter);

    // ascii code for '0' to '9' are sequntial, starting at 48
    // so we can subtract '0' to obtain the integer value
    if(letter >= '0' && letter <= '9') {
        return letter - '0';
    } else if(letter >= 'A' && letter <= 'F') {
        // A - A = 0, A to F are sequential, so this gives us 10 - 15
        return letter - 'A' + 10;
    } else {
        return -1;
    }
}

int binToDec() {
    cout << "Please enter a binary number: ";

    int total = 0;
    int num = 0;
    
    while(num == 0 || num == 1) {
        num = charToInt(getchar());
        if(num != -1) {
            total = total * 2 + num;
        }
    }

    return total;
}

int hexToDec() {
    cout << "Please enter a hexidecimal number: ";

    int total = 0;
    int num = 0;

    while(num >= 0 && num <=15) {
        num = charToInt(getchar());
        if(num != -1) {
            total = total * 16 + num;
        }
    }

    return total;
}