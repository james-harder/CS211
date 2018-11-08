#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(void){
    string words[3] = {"one", "two", "three"};
    
    for(int i = 1; i <= 3; i++){
        cout << words[i] << endl;
    }
    return 0;
}