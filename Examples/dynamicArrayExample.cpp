#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int rows;
    int cols;

    cout << "Rows: ";
    cin >> rows;
    cout << "Cols: ";
    cin >> cols;

    /*
     * We must declare a pointer to a pointer to an integer (double pointer to 
     * an integer) because a 2-D array is really an array of arrays, and an 
     * array is a pointer in disguise
     * 
     * What I allocate here is an array of pointers to integers (each element 
     * will hold an address)
     */
    int **arr = new int*[rows];

    /*
     * The array declared above is still 1-D. But each element is a pointer, 
     * meaning they are capable of allocating their own 1-D arrays. The 
     * collection of 1-D arrays will make up our 2-D array of arrays
     */
    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j + 1;   // Just putting values into the array
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(3) << arr[i][j] << ' ';    // Printing and formatting so that 
        }                                           // up to 3-digit numbers still look nice
        cout << endl;
    }

    /*
     * In order to delete all the dynamic memory correctly, we go in reverse 
     * order with respect to how we allocated the memory. 
     * 
     * So first, we delete the individal 1-D arrays that make up our 2-D array
     * 
     * Then, we can delete the array of pointers to to integers
     */
    for (int i = 0; i < rows; i++) {
        delete [] arr[i];
        arr[i] = nullptr;
    }
    delete [] arr;
    arr = nullptr;

    return 0;
}