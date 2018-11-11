#include <iostream>

using namespace std;

int main()
{
	int arr[10], *parr;

	for (int i = 0; i < 10; i++)
		arr[i] = i;

	parr = arr;

	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;
	
	for (int i = 0; i < 10; i++)
		parr[i]++;
	
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;
	
	return 0;
}