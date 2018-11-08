#include <iostream>

using namespace std;

int main()
{
	int size;

	cout << "How large do you need your array? ";
	cin >> size;

	int *dynArray = new int[size];

	for (int i = 0; i < size; i++)
		dynArray[i] = i + 1;
	
	for (int i = 0; i < size; i++)
		cout << dynArray[i] << " ";
	cout << endl;
	
	return 0;
}