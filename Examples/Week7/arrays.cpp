#include <iostream>

using namespace std;

int main()
{
    char grades[5] = {'A', 'C', 'A', 'B', 'F'};

    for (int i = 0; i < 5; i++) {
        cout << grades[i] << endl;
    }

    // const int BIG_SIZE = 789;
    // double big[BIG_SIZE];

    // for (int i = 0; i < BIG_SIZE; i++) {
    //     big[i] = 0.0;
    // }

    return 0;
}