#ifndef MONEY_HPP
#define MONEY_HPP

#include <iostream>

class Money {
    public:
        Money();
        Money(int d, int c);
        Money(int d);
        Money(double m);
        Money add(Money r);
        int get_dollars() const;
        int get_cents() const;
        void set_dollars(int d);
        void set_cents(int c);
        const Money operator+(const Money &rhs); 
        friend std::ostream& operator<<(std::ostream &sout, const Money &rhs);
    private:
        int dollars;
        int cents;

        int makePennies() const;
};

const Money operator-(const Money &lhs, const Money &rhs);

#endif