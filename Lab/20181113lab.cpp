/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			lab12
* Description:	Creates an 'Album' object, fills the data and prints it
*
*
~cs211b/bin/handin lab12 20181113lab.cpp
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
using std::string;

struct Album {
    string artist;
    string title;
    int year;
    int numTracks;
    double rating;
};

// prints contents of album 
void printAlbum(Album al);

// fills and returns an Album struct. 
// performs some checking on values passed, returns blank Album on bad input
Album fillAlbum(string artist, string title, int year, int tracks, float rating);

int main(void) {
	
    Album al = fillAlbum(string("Yo La Tengo"), string("And Nothing Turned Itself Inside Out"), 2000, 13, 5.0);

    printAlbum(al);

	return 0;	
}

void printAlbum(Album al) {
    
    // All of this just to keep from typing setw(8) five times...
    const int numFeilds = 5;
    string **feilds = new string*[numFeilds];
    for(int i = 0; i < numFeilds; i++) {
        feilds[i] = new string[2];
        switch(i) {
            case 0:
                feilds[i][0] = string("Artist: ");
                feilds[i][1] = al.artist;
                break;
            case 1:
                feilds[i][0] = string("Title: ");
                feilds[i][1] = al.title;
                break;
            case 2:
                feilds[i][0] = string("Year: ");
                feilds[i][1] = to_string(al.year);
                break;
            case 3:
                feilds[i][0] = string("Tracks: ");
                feilds[i][1] = to_string(al.numTracks);
                break;
            case 4:
                stringstream str;
                str << std::fixed << std::setprecision(2) << al.rating;
                string rating = str.str();
                feilds[i][0] = string("Rating: ");
                feilds[i][1] = rating;
                break;            
        }
    }

    // format and print feilds of album
    for(int i = 0; i < numFeilds; i++) {
        cout << setw(8) << feilds[i][0] << feilds[i][1] << "\n";
    }

    cout << endl;

    return;
}

Album fillAlbum(string artist, string title, int year, int tracks, float rating) {
    Album al;

    al.artist = artist;
    al.title = title;
    al.year = year;
    al.numTracks = tracks;
    al.rating = rating;

    return al;
}