#include <iostream>

using namespace std;

/*
 * Goal: Find cheapest of two pizzaa based on $/in^2
 * 
 * STEPS:
 * Get size and price information of two pizzas from user
 * Calculate Pizza Price Per Square Inch (PPPSI) for both pizzas
 *  - repetive calculation, will want function
 * Compare pizzas based on PPPSI
 * Print more economical pizza to screen
 * 
 * VARIABLES:
 * Two integers for pizza sizes
 * Two doubles for pizza prices
 * 
 */


// Returns PPPSI, diameter is in inches
// NOTE: must include <cmath>
double calcPPPSI(double price, int diameter);
// calcPPPSI(double, int)
double calcPPPSI(double price, int length, int width);
// calcPPPSI(double, int, int)

int main()
{
    int size_1;
    int length;
    int width;
    double price_1;
    double price_2;
    double pppsi_1;
    double pppsi_2;

    cout << "Enter Information for Round Pizza\n";
    cout << "\tSize (in): ";
    cin >> size_1;
    cout << "\tPrice: $";
    cin >> price_1;
    cout << "\nEnter Information for Rectangular Pizza\n";
    cout << "\tLength (in): ";
    cin >> length;
    cout << "\tWidth (in): ";
    cin >> width;
    cout << "\tPrice: $";
    cin >> price_2;

    pppsi_1 = calcPPPSI(price_1, size_1);
    pppsi_2 = calcPPPSI(price_2, length, width);

    if (pppsi_1 < pppsi_2)
        cout << "First Pizza is more economical at $" << pppsi_1 << "\n";
    else
        cout << "Second Pizza is more economical at $" << pppsi_2 << "\n";

    return 0;
}

double calcPPPSI(double price, int diameter)
{
    /*
     * Find radius
     * Calculate area
     *  - pi*r^2
     * Divide price by area ($/in^2)
     */
    const double PI = 3.141592653589793238462433;

    double radius = diameter / 2.0;

    return price / (PI * radius * radius);
}

double calcPPPSI(double price, int length, int width)
{
    return price / (length * width);
}