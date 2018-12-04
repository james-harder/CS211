#include <iostream>

using namespace std;

// argc and argv are conventional names for parameters, but they can be named anything
// parameters are passed as c-strings (char arrays ending in null)
int main(int argc, const char ** argv) {
    if(argc < 2) {
        cerr << "USAGE: ./a.out --[BLAH]\n";

        return -1;
    }

    for(int i = 1; i <= argc; i++) {
        cout << argv[i] << '\n';
    }
    return 0;
}