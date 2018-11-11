#include <iostream>

using namespace std;

int main(void) {
  double grossPay;
  int hoursWorked;
  double hourlyRate;

  cout << "Enter the hourly rate: $";
  cin >> hourlyRate;
  cout << "Enter hours worked (rounded to nearest hour): ";
  cin >> hoursWorked;

  // THE PART WE CARE ABOUT
  if (hoursWorked < 40)
    grossPay = hoursWorked * hourlyRate;
  else
    grossPay = 40 * hourlyRate + hourlyRate * 1.5 * (hoursWorked - 40);
  // /THE PART WE CARE ABOUT

  cout << "Gross pay: $" << grossPay << endl;

  return 0;
}
