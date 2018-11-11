/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			HW 06
* Description:	Accepts a message from the user of up to 200 characters. The message is then shifted (ceasar shift) and displayed.
*
*
*/

#include <iostream>
#include <cctype>

// CAP is the maximum length of the message
// SHIFT is the amount of characters to shift each letter
const int CAP = 200, SHIFT = 4;

// encodeMsg() accepts an array of char and returns the encoded msg
// decodeMsg() accepts an encoded array and prints the decoded msg
void encodeMsg(char* inputMsg, char* outputMsg, int size);
void decodeMsg(char* msg, int size);

using namespace std;

int main(void){
	char inputMsg[CAP];
    char encodedMsg[CAP];
    // record the size of user message
    int size = 0;
    // temp buffer
    char buff;
    
    // get user input
    while(size < CAP){
        buff = cin.get();
        if(buff == '\n'){
            break;
        }else{
            inputMsg[size] = buff;
            size++;
        }
    }
    
    // encode the message
    encodeMsg(inputMsg, encodedMsg, size);

    // decode the message
    decodeMsg(encodedMsg, size);

	return 0;	
}

void encodeMsg(char* inputMsg, char* encodedMsg, int size){
    // shift characters to encode
    for(int i = 0; i < size; i++){
        inputMsg[i] = toupper(inputMsg[i]);
        if(inputMsg[i] >= 65 && inputMsg[i] <= 90){
            encodedMsg[i] = inputMsg[i] + SHIFT;
            if(encodedMsg[i] > 90){
                encodedMsg[i] -= 26;
            }
        }else{
            encodedMsg[i] = inputMsg[i];
        }
        cout << i << ")" << "o: " << (int)inputMsg[i] << "; e: " << (int)encodedMsg[i] << endl;
    }
    
    //cout << (int)inputMsg[size] << endl;
    //cout << (int)encodedMsg[size] << endl;

    // print unencoded message
    //cout << inputMsg << endl;

    // print encoded message
    //cout << encodedMsg << endl;

    return;
}

void decodeMsg(char* msg, int size){
    char temp[CAP];

    // shift characters the other way and print them
    for(int i = 0; i < size; i++){
        if(msg[i] >= 65 && msg[i] <= 90){
            temp[i] = msg[i] - 4;
            if(temp[i] < 65){
                temp[i] += 24;
            }
        }else{
            temp[i] = msg[i];
        }
    }

    //cout << temp << endl;

    return;
}