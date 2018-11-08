#include <iostream>

const int ROWS = 10;
const int COLS = 10;

int main (void){
    // create a two dimensional array of integers

    int **rows = new int*[ROWS];          // rows is a pointer to a pointer; it is assigned an array(which is a pointer) of pointers to integer
    for(int i = 0; i < ROWS; i++){
        rows[i] = new int[COLS];          // each element of rows(which is a pointer) is assigned to a dynamically created array of integers(which is a pointer to integers)
    }

    for(int j = 0; j < ROWS; j++){
        for(int k=0; k < COLS; k++){
            rows[j][k] = k;
            std::cout << rows[j][k];

        }
        std::cout << std::endl;
    }

    for(int i; i < ROWS; i++){
        delete [] rows[i];
        rows[i] = nullptr;
    }

    delete [] rows;
    rows = nullptr;
    
    return 0;
}