#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    /* #
     * ##
     * ###
     * ####
     * ###
     * ##
     * #
     */
     for (int j =1; j <= 5; j++) {
        for (int i = 1; i <= (6 - j); i++) {
            cout << "#";
        }
        cout << "\n";
    }

    return 0;
}
