#include <iostream>
#include <ctime>
#include <random>

using namespace std;

void printArray(const int arr[], int cap);
// Note to self: study why we would use a 'const' array
void selectionSort(int arr[], int cap);

int main(void){
    const int CAP = 10;
    int nums[CAP];
    srand(time(0));

    for(int i = 0; i < CAP; i++){
        nums[i] = rand() % 100 + 1;
    }

    printArray(nums, CAP);

    return 0;
}

void printArray(const int arr[], int cap){
 for(int i = 0; i < cap; i++){
     cout << arr[i] << endl;
 }
}

void selectionSort(int arr[], int cap){

}