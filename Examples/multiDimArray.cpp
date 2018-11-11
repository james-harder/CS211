#include <iostream>
#include <string>

using namespace std;

const int ENTRIES = 10;
const int WORDS = 2;

int main(){
    string **dict = new string*[ENTRIES];
    for(int i = 0; i < ENTRIES; i++){
        dict[i] = new string[WORDS];
    }

    for(int i = 0; i < ENTRIES; i++){
        for(int j = 0; j < WORDS; j++){
            string eye, jay;
            ostringstream convert;
            convert << i;
            eye = convert.str();
            convert << j;
            jay = convert.str();
            dict[i][j] = eye + " " + jay;
        }
    }

    for(int i = 0; i < ENTRIES; i++){
        for(int j = 0; j < WORDS; j++){
            cout << dict[i][j];
        }
        cout << "\n";
    }

    cout << endl;

    return 0;
}