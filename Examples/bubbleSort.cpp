/*
// Bubble-Sort Algorithm Psuedo-Code

procedure bubbleSort( A : list of sortable items)
    n = length(A)
    repeat
      swapped = false
      for i = 1 to n - 1 inclusive do
       ifA[i-1] > A[i] then
        swap(A[i-1], A[i])
        swapped = true
    end if
  end for
 until not swapped
end procedure

*/

#include <iostream>
#include <ctime>
#include <random>

using std::cout;
using std::endl;

const int SIZE = 10;

void fillArray(int arr[], const int size);
void printArray(int arr[], const int size);
void bubbleSort(int arr[], const int size);
void swapElement(int arr[], const int ind1, const int ind2);


int main(void){
	int grades[SIZE] = {0};
	
	fillArray(grades, SIZE);

	printArray(grades, SIZE);

	bubbleSort(grades, SIZE);

	printArray(grades, SIZE);
	
	return 0;    
}

void fillArray(int *arr, const int size){
	//std::cout << "inside fillArray" << std::endl;
	std::srand(std::time(0));

	for(int i = 0; i < SIZE; i++){
		*(arr + i) = rand() % 100;
	}
	return;
}

void bubbleSort(int arr[], const int size){
	bool swap = true;
	
	while(swap){							// if flag is set to false, no changes were made
		swap = false;						// assume array is in order
		for(int i = 1; i <= size; i++){		// loop through array
			if(arr[i -1] > arr[i]){			// if elements are out of order
				swapElement(arr, i-1, i);	// swap elements
				swap = true;				// set flag so loop repeats
			}
		}
	}
	return;
}

void printArray(int arr[], const int size){
	for(int i = 0; i < size; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return;
}

void swapElement(int arr[], const int ind1, const int ind2){
	int temp = arr[ind1];
	arr[ind1] = arr[ind2];
	arr[ind2] = temp;

	return;
}