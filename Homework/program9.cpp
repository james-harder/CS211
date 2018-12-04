/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			HW09
* Description:	Loads temperature data from file. Asks user for a temperature and
*				reports all days where recorded temperature is higher than the
*				input. The program also reports the average temperature from all 
*				days and the max, min and mean of temperature for each day.
*/

#include <iostream>
#include <iomanip>
#include <array>
#include <fstream>

using namespace std;

const int DAYS = 7;
const int HOURS = 24;

void get_data(double (&temperature)[DAYS][HOURS], int days);
double FtoC(double fTemp);
void show_warmer(double temperature[][HOURS], int days, double cutoff);
double find_average(double temperature[][HOURS], int days);
void find_daily_mmm(double day_temps[], double &max, double &min, double &mean);
void print_data(double temp[][HOURS], int days);
double get_cutoff();

int main(void){
	// create 2d array to hold temp data
    double celsius[DAYS][HOURS];

    // read data from file, convert to celsius and assign to array
    get_data(celsius, DAYS);

    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);

    show_warmer(celsius, DAYS, get_cutoff());

    cout << "The average temperature over all days was " << find_average(celsius, DAYS) << '\n' << endl;
    
    double max = 0.0, min = 0.0, mean = 0.0;
    for(int i = 0; i < DAYS; i++) {
        find_daily_mmm(celsius[i], max, min, mean);
        cout << "day " << i+1 << ": max: " << max << " min: " << min << " mean: " << mean << " " << '\n';
    }

    cout << endl;

	return 0;	
}

// gets data from file. The data is converted to celsius and then assigned 
// to the array at the address passed as temperature
void get_data(double (&temperature)[DAYS][HOURS], int days) {
    ifstream dataFile("temperature.dat");

    // check to make sure the file opened, if not exit()
    if(dataFile.fail()) {
        cerr << "Unable to open temperature.dat." << endl;
        exit(1);
    }

    // loop until all days are read, or eof is found
    for(int i = 0; i < days && !(dataFile.eof()); i++) {
        for(int j = 0; j < HOURS; j++) {
            dataFile >> temperature[i][j];
            temperature[i][j] = FtoC(temperature[i][j]);
        }
    }
    
    // close file
    dataFile.close();
    
    return;
}

// converts from farhenheit to celsius
double FtoC(double fTemp) {
    return ((fTemp - 32) * 5 / 9);
}

// Takes an array of celsius temperatures and prints all data point
// where the temperature is higher than 'cutoff'
void show_warmer(double temperature[][24], int days, double cutoff) {
    cout << "Times at which temperatures warmer than " << cutoff << "C were found:\n\n";

    for(int i = 0; i < days; i++) {
        for(int j = 0; j < HOURS; j++) {
            if(temperature[i][j] > cutoff) {
                cout << "At day, " << i << ", hour " << setw(2) << j << " the temperature was " << temperature[i][j] << "\n";
            }
        }
    }

    // for formatting purposes...
    cout << endl;

    return;
}

// returns the average temperature of all days in the temperature array
double find_average(double temperature[][24], int days) {
    double avg_temp = 0;

    for(int i = 0; i < days; i++) {
        for(int j = 0; j< days; j++) {
            avg_temp += temperature[i][j];
        }
    }

    avg_temp /= (days * HOURS);

    return avg_temp;
}

// calculates max, min and mean for the data in the day_temps array
// and assigns them to the variables at the addresses passed
// day_temps[] should contain the data for one day
void find_daily_mmm(double day_temps[], double &max, double &min, double &mean) {
    //set max and min to the first double in the array
    max = day_temps[0];
    min = day_temps[0];
    mean = 0.0;

    for(int i = 0; i < HOURS; i++) {
        if(day_temps[i] > max) {
            max = day_temps[i];
        } else if(day_temps[i] < min) {
            min = day_temps[i];
        }
        mean += day_temps[i];
    }
    mean /= HOURS;

    return;
}

// used for debugging program
void print_data(double temp[][HOURS], int days) {
    for(int i = 0; i < days; i++) {
        for(int j = 0; j < HOURS; j++) {
            cout << temp[i][j] << " ";
        }
        cout << '\n';
    }
    cout << endl;

    return;
}

double get_cutoff() {
    // prompt user for cutoff value
    double cutoff = 0;    
    cout << "Enter the value for which to find warmer temperatures (C): ";
    cin >> cutoff;
    cout << endl;

    return cutoff;
}