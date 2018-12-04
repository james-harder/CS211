#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

using namespace std;

int main() {
    vector<int> vec;

    // uses a hardware device to create a seed value
    // pseudo random algorithm
    random_device seed;
    mt19937 engine(seed());
    //default_random_engine(seed());
    uniform_int_distribution<unsigned int> d12(1, 12);  // creates a uniform distribution of random numbers from 1 to 12

    cout << "Size: " << setw(3) << vec.size()
         << "\tCapacity: " << setw(3) << vec.capacity() << '\n';

    // Note, when a vector is full and another item is added, the
    // capacity of the vector is doubled.
    // When a vector needs to grow, it creates a new array (on the heap)
    // and moves the values to it. This all happens w/o us having to worry
    // about dealing with creating and destroying memory.
    for(int i = 0; i < 20; i++) {
        vec.push_back(d12(engine));
        cout << "Size: " << setw(3) << vec.size()
             << "\tCapacity: " << setw(3) << vec.capacity() << '\n';
    }

    cout << "\n\n\n";

    // same as: vec[12] = 99; except that it includes some
    // error checking.
    vec.at(12) = 99; 

    for(auto i : vec) {     // for-each loop; auto deduces type of element in vector
        cout << i << " ";   // this i is a copy, not a reference
    }
    cout << "\n\n\n";
    
    // N.B. when items are removed from a vector, the size of the 
    // vector never shrinks. This is to prevent poor performance 
    // when dealing with datasets that grow and shrink. 
    for(int i = 0; i < 20; i++) {
        vec.pop_back();
        cout << "Size: " << setw(3) << vec.size()
             << "\tCapacity: " << setw(3) << vec.capacity() << '\n';
    }

    return 0;
}