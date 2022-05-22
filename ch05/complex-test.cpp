#include "complex.h"
#include <iostream>

int main() {
    using namespace std;

    // Constructor operator tests
    Complex c1(3.4, 5.6);
    Complex c2(7.8, 1.2);
    Complex c3(1.0);

    // Arithmetic operator tests
    cout << "Testing complex number arithmetic:" << endl
         << c1 << " + " << c2 << " = " << c1 + c2 << endl
         << c1 << " - " << c2 << " = " << c1 - c2 << endl
         << c1 << " * " << c2 << " = " << c1 * c2 << endl
         << c1 << " / " << c2 << " = " << c1 / c2 << endl << endl;

    // Arithmetic assignment operator tests
    cout << "Testing complex number assignment operators:" << endl
         << c1 << " += " << 1.0 << " = ";
    c1 += 1.0;
    cout << c1 << endl
         << c2 << " -= " << 1.0 << " = ";
    c2 -= 1.0;
    cout << c2 << endl
         << c3 << " += " << c1 << " = ";
    c3 += c1;
    cout << c3 << endl
         << c2 << " -= " << c1 << " = ";
    c2 -= c1;
    cout << c2 << endl
         << c1 << " *= " << 1.0 << " = ";
    c1 *= 1.0;
    cout << c1 << endl
         << c2 << " /= " << 1.0 << " = ";
    c2 /= 1.0;
    cout << c2 << endl
         << c3 << " *= " << c1 << " = ";
    c3 *= c1;
    cout << c3 << endl
         << c2 << " /= " << c1 << " = ";
    c2 /= c1;
    cout << c2 << endl;

    // Comparison operator tests
    cout << c1 << (c1 != c2 ? " != " : " == ") << c2 << endl
         << c1 << (c1 == c1 ? " == " : " != ") << c1 << endl;

    return 0;
}
