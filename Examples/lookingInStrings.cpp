#include <iostream>
#include <string>

using namespace std;

string hear();
void say(string str);

int main(){
    
    string phrase = hear();
    
    say(phrase);

    return 0;
}

string hear(){
    string temp = "";

    cout << "Please enter a  sentence: ";
    getline(cin, temp);

    size_t found = temp.find_first_of(" \t\n\r,.!'?");;

    while(found != string::npos){
        temp.erase(found, 1);
        found = temp.find_first_of(" \t\n\r,.!'?;\"");
    }

    return temp;
}

void say(string str){
    int spaces = 12 - (str.size() % 12);
    string filler(spaces, '#');
    str += filler;

    // debugging
    // cout << str;
    // cout << "size of str: " << str.size() << "\n";
    // cout << str.size() % 12 << "\n";
    // cout << "filler: " << filler << endl;
    // end debugging

    for(size_t i = 0; i < str.size(); i++){
        if(i % 12 == 0){
            cout << "\n" << str[i];
        }else{
            cout << str[i];
        }
    }
    cout << endl;

    return;
}