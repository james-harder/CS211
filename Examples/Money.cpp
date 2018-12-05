#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Money.hpp"


Money::Money() {
	dollars = 0;
	cents = 0;
}

Money::Money(int d, int c) {
	dollars = d;
	cents = c;
}

Money::Money(double money) {
	int pennies = round(money * 100);
	dollars = pennies / 100;
	cents = pennies % 100;
}

int Money::get_dollars() const {
	return dollars;
}

int Money::get_cents() const {
	return cents;
}

void Money::set_dollars(int d) {
	dollars = d;
}

void Money::set_cents(int c) {
	cents = c;
}

Money Money::add(Money r) {
	int leftPennies = (dollars * 100) + cents;
	int rightPennies = (r.dollars * 100) + r.cents;

	int sum = leftPennies + rightPennies;
	Money temp(sum / 100, sum % 100);

	return temp;
}

Money inputMoney() {
	std::string m;
	do {
		std::cout << "How much money do you have ($d.cc)? ";
		std::cin >> m;

		if (m.at(0) == '$')
			break;
	} while(1);

	double amount = std::stod(m.substr(1, std::string::npos));

	return Money(amount);
}

const Money operator+(const Money& left, const Money& right) {
	int leftPennies = (left.get_dollars() * 100) + left.get_cents();
	int rightPennies = (right.get_dollars() * 100) + right.get_cents();

	int sum = leftPennies + rightPennies;

	return Money(sum / 100, sum % 100);
}

std::ostream& operator<<(std::ostream& sout, const Money& rhs) {
	if (rhs.get_dollars() < 0 || rhs.get_cents() < 0)
		sout << "(";
	
	sout << "$" << abs(rhs.get_dollars()) << ".";

	if (abs(rhs.get_cents()) < 10)
		sout << "0" << abs(rhs.get_cents());
	else
		sout << abs(rhs.get_cents());
	
	if (rhs.get_dollars() < 0 || rhs.get_cents() < 0)
		sout << ")";
	
	return sout;
}