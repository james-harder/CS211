/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			HW09
* Description:	Loads temperature data from file. Asks user for a temperature and
*				reports all days where recorded temperature is higher than the
*				input. The program also reports the average temperature from all 
*				days and the max, min and mean of temperature for each day.
*/

// A Template for class submissions - CS211
// N.B. address for uploading assignments:
// cslab-sftp.cs.wichita.edu

#include <iostream>
#include <iomanip>

using namespace std;

void show_warmer(double temperature[][24], int days, double cutoff);
double find_average(double temperature[][24], int days);
void find_daily_mmm(double day_temps[], double &max, double &min, double &mean);

int main(void){
	// create 2d array to hold temp data
    celsius[7][24];
    // read data from file, convert to celsius and assign to array

    // prompt user for cutoff value
    int cutoff = 0;    
    cout << "Enter cutoff: ";
    cin >> cutoff;

    // call show_warmer
    show_warmer(celsius, cutoff)
    // call find_average

    // call find_daily_mmm

	return 0;	
}

void show_warmer(double temperature[][24], int days, double cutoff) {
    for(int day = 1; day <= days; day++) {
        for(int hour = 1; hour < 25; hour++) {
            cout << "Day: " << day << " Hour: " << hour << "\n";
        }
    }
    return;
}

double find_average(double temperature[][24], int days) {
    double avg_temp = 0;

    return avg_temp;
}

void find_daily_mmm(double day_temps[], double &max, double &min, double &mean) {

    return;
}
