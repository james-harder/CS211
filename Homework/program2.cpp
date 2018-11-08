/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			HW 2
* Description:	This program prompts the user to enter a loan amount
*               an interest rate, the monthly payment and the number 
*               of years to simulate. The program will then output a 
*               table for each year, showing the interest and principal 
*               paid for each month.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(void){

    // declare needed variables
    double remainingPrincipal = 0, interestRate = 0, monthlyPayment = 0;
    double monthlyRate = 0; //this is calculated based on the APR entered
    int years = 0;

    // Ask the user to input: loanAmount, interestRate, monthlyPayment, numYears
    cout << "Enter amount of loan:\t";
    cin >> remainingPrincipal;
    cout << "Enter interest rate:\t";
    cin >> interestRate;
    cout << "Enter monthly payment:\t";
    cin >> monthlyPayment;
    cout << "Years to simulate:\t";
    cin >> years;

    // Loop through each year
    for(int i = 1; i <= years; i++){
        // Declare variables to hold the sum of monthly payments for each year
        double interestPaidYear = 0, principalPaidYear = 0;
        
        // Print annual header
        cout << "Year " << i << "\t" << "Interest" << "\t" << "Principal" << endl;

        //  loop through each month
        for(int j = 1; j <= 12; j++){
            double interestPaid = remainingPrincipal * monthlyRate; // Calculate interestPaid for the remainingPrincipal
            double principalPaid = monthlyPayment - interestPaid;   // Subtract monthlyInterest from monthlyPayment to find principalPaid

            // Add interestPaid and principalPaid to the yearly sumInterestPaid and sumPrincipalPaid
            interestPaidYear += interestPaid;
            principalPaidYear += principalPaid;

            // Display interestPaid and principalPaid for the month
            cout << "\t" << i << ":" << "\t" << interestPaid << "\t" << principalPaid << endl;
        }

        // Print annual totals and remaining balance for the year
        cout << "Year " << i << " totals:" << "\t" << interestPaidYear << "\t" << principalPaidYear << endl;
        cout << "Remaining principal at year end:" << "\t" << remainingPrincipal << endl;
    }
    
	return 0;
	
}