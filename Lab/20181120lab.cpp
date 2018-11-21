/*
* NAME:			James Harder
* WSUID:		s674k343
* HW #:			lab13
* Description:	Defines a Pair class. In main severl Pair objects are instantiated and the values of the Pair objects is printed.
*
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Pair {
    public:
        Pair();
        Pair(int a, int b);
        void print();
        Pair add(Pair p);
        int setx(int n);
        int sety(int n);
        int getx();
        int gety();
    private:
        int x;
        int y;
};

int main(void){
	Pair p;                     // default initialization
    Pair t(1,2);                // parameterized initialization
    Pair n = p.add(t);          // use class method to create new object
    p.setx(5);                  // change p.x with setter method
    p.sety(10);                 // change p.y with setter method
    t = n.add(p);

    p.print(); cout << " + "; n.print(); cout << " = "; t.print(); cout << endl;

    return 0;	
}

Pair::Pair() {
    x = 0;
    y = 0;
}

Pair::Pair(int a, int b) {
    x = a;
    y = b;
}

void Pair::print() {
    cout << "(" << x << ", " << y << ")";

    return;
}

Pair Pair::add(Pair p) {
    return Pair(x + p.x, y + p.y);
}

int Pair::setx(int n) {
    return x = n;
}

int Pair::sety(int n) {
    return y = n;
}

int Pair::getx() {
    return x;
}

int Pair::gety() {
    return y;
}