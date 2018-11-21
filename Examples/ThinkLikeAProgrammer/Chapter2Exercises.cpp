/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			XXXX
* Description:	XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX 
*
* Make the following shapes with only three output statements:
* cout << '#' and cout << ' ' and cout << '\n'
    ########        8x'#'
     ######
      ####
       ##
    
    ##              2x'#', 6x' '
      ####
     ######
    ########
    ########
     ######
      ####
       ##
    
    #            #  2x'#', 12x' '
     ##        ##
      ###    ###
       ########
       ########
      ###    ###
     ##        ##
    #            #
*/

// A Template for class submissions - CS211
// N.B. address for uploading assignments:
// cslab-sftp.cs.wichita.edu

#include <iostream>
#include <iomanip>

using namespace std;

int ab(int n);

int main(void){
    for(int i = -3; i <= 3; i++) {
        for(int j = 4 - ab(i); j > 0; j--) {
            cout << '#';
        }
    cout << '\n';
    }

    cout << '\n' << endl;

    int j = 0;
    for(int i = 8; i > 4; --i) {
        cout << std::right << std::setw(9 - i);
        for(int k = i - j; k > 0; k--) {
            cout << '#';
            //cout << "i: " << i << " k: " << k << '\n';
        }
        cout << '\n';
        j++;
    }

    
	
	return 0;	
}

int ab(int n) {
    if( n < 0){
        return n * -1;
    } else {
        return n;
    }
}