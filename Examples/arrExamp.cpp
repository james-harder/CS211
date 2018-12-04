#include <iostream>

using namespace std;

int main() {
    int arr[10];
    for(int i = 0; i < 10; i++) {
        arr[i] = 0;
    }

    cout << sizeof(arr) / sizeof(int) << endl;

    return 0;
}