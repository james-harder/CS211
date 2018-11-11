/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			HW03
* Description:	This program prints shapes 
*
*
*/

#include <iostream>

using namespace std;

//Function to print shapes defined in main()
//Accepts a two dimensional array that defines the shape
void printShape(bool arr[][8], int width, int height);

int main(void){
	//define shapes
	bool triangle[7][8] = {{1,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,0},{0,0,1,1,1,1,0,0},{0,0,0,1,1,0,0,0}};
	int tWidth = 8, tHeight = 5;
	bool diamond[7][8] = {{0,0,0,1,0,0,0},{0,0,1,0,1,0,0},{0,1,0,0,0,1,0},{1,0,0,0,0,0,1},{0,1,0,0,0,1,0},{0,0,1,0,1,0,0},{0,0,0,1,0,0,0}};
	int dWidth = 7, dHeight = 7;
	bool exe[7][8] = {{1,0,0,0,0,0,1},{0,1,0,0,0,1,0},{0,0,1,0,1,0,0},{0,0,0,1,0,0,0},{0,0,1,0,1,0,0},{0,1,0,0,0,1,0},{1,0,0,0,0,0,1}};
	int xWidth = 7, xHeight = 7;
	bool rect[7][8] = {{1,1,1,1,1,1,1},{1,0,0,0,0,0,1},{1,0,0,0,0,0,1},{1,0,0,0,0,0,1},{1,1,1,1,1,1,1}};
	int rWidth = 7, rHeight = 5;

	//Call printShape for each shape 
	printShape(triangle, tWidth, tHeight);
	printShape(diamond, dWidth, dHeight);
	printShape(exe, xWidth, xHeight);
	printShape(rect, rWidth, rHeight);
	
	return 0;
	
}

void printShape(bool arr[][8], int width, int height){
	//loop through first dimension of shape arrray
    for(int i = 0; i < height; i++){
        //loop through second dimension of shape array
        for(int j = 0; j < width; j++){
            if(arr[i][j]){
                cout << "#";
            }else{
                cout << " ";
            }
        }
        cout << "\n";
    }

    cout << "\n\n";

	return;
}