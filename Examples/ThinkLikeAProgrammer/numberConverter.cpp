#include <iostream>
#include <vector>

using namespace std;
using std::vector;

// convert a char to its integer value
int charToInt(char letter);

// convert binary to decimal
int binToDec(vector<int> number);

int main(){
    cout << "Please enter a binary number: ";

    vector<int> number;
    int num = 0;
    while(num == 0 || num == 1) {
        num = charToInt(getchar());
        if(num != -1) {
            number.push_back(num);
        }
    }

    cout << binToDec(number) << endl;
    
    return 0;
}

int charToInt(char letter) {
    // ascii code for '0' to '9' are sequntial, starting at 48
    // so we can subtract '0' to obtain the integer value
    if(letter >= '0' && letter <= '9') {
        return letter - '0';
    } else {
        return -1;
    }
}

int binToDec(vector<int> number) {
    int total = 0;
    //read a character
    //if 1 or 0, multiply total by 2 and add digit
    //repeat until not 1 or 0
    for(vector<int>::iterator it = number.begin(); it != number.end(); it++) {
        total = total * 2 + *it;
    }
    
    return total;
}