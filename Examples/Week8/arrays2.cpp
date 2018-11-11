#include <ctime>
#include <iostream>
#include <random>

using namespace std;

const int SIZE = 500;

// Returns the index number where 'value' was found. Assumes value can be found
int searchArray(const int a[], const int size, const int value);

int main()
{
    srand(time(NULL));  // Needed for random number generator
    int arr[SIZE]; 
    
    for (int index = 0; index < SIZE; index++)  // Initialize all elements to 20
        arr[index] = 20;
    
    arr[rand() % SIZE] = 30;  // Randomly assign one element to be 30, 
                             // We'll then look for it
    
    int found = searchArray(arr, SIZE, 30);
    
    cout << "Found value 30 at index " << found << endl << endl;
    
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    
    return 0;
}

int searchArray(const int a[], const int size, const int value)
{
    int i = 0;
    while (a[i] != value && i < size)
        i++;
    
    if (i >= size)
        return -1;
    else
        return i;
}