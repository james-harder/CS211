#include <iostream>

using namespace std;

// Accepts user input and fills array, returns number of entries
int fillArray(int a[], const int size);

// Calculates average of partially-filled array
double computeAverage(const int a[], const int numUsed);

// Prints difference of each score and average
void showDifference(const int a[], const int numUsed);

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

int main()
{
    const int MAX_NUM_SCORES = 10;
    int score[MAX_NUM_SCORES], numUsed;
    
    cout << "I will read in golf scores and show their difference from the average\n";
    
    numUsed = fillArray(score, MAX_NUM_SCORES);
    cout << "SIZE: " << numUsed << endl;
    printArray(score, MAX_NUM_SCORES);
    showDifference(score, numUsed);
    
    return 0;
}

int fillArray(int a[], const int size)
{
    int score, index = 0;
    
    cout << "Enter up to " << size << " non-negative whole numbers.\n"
        << "Mark the end of the list with a negative number.\n";
    cout << "Score" << index << ": ";
    cin >> score;
    while (score > 0 && index < size)
    {
        a[index] = score;
        index++;
        if (index >= size)
            break;
        cout << "Score" << index << ": ";
        cin >> score;
    }
    
    cout << endl;
    
    return index;   // Due to the way the loop works, index == numUsed at this point
}

double computeAverage(const int a[], const int numUsed)
{
    int sum = 0;
    
    if (numUsed <= 0)
        return 0;
    
    for (int i = 0; i < numUsed; i++)
        sum += a[i];
    
    return static_cast<double>(sum) / numUsed;
}

void showDifference(const int a[], const int numUsed)
{
    double average = computeAverage(a, numUsed);
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    
    cout << "Average of the " << numUsed << " scores: " << average << endl
        << "The scores are:\n";
    for (int i = 0; i < numUsed; i++) {
        cout << a[i] << " differs from average by " << (a[i] - average) << endl;
    }
}









