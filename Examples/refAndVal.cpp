#include <iostream>

using namespace std;

void changeIt(int &i);

int main() {
    int i = 5;
    cout << i << endl;

    changeIt(i);
    cout << i << endl;

    return 0;
}

void changeIt(int &i) {
    i = 0;

    return;
}