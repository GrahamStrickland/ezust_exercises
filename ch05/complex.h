#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class Complex {
    // binary nonmember friend function declarations
    friend ostream& operator<<(ostream& out, const Complex& c);
        // Overloaded insertion operator for complex numbers.

    friend Complex operator+(const Complex& c1, const Complex& c2);
        // Overloaded addition operator for complex numbers.

    friend Complex operator-(const Complex& c1, const Complex& c2);
        // Overloaded subtraction operator for complex numbers.
        
    friend Complex operator*(const Complex& c1, const Complex& c2);
        // Overloaded multiplication operator for complex numbers.

    friend Complex operator/(const Complex& c1, const Complex& c2);
        // Overloaded division operator for complex numbers.

    friend bool operator!=(const Complex& c1, const Complex& c2);
        // Overloaded inequality comparison operator for complex numbers;

    friend bool operator==(const Complex& c1, const Complex& c2);
        // Overloaded equality comparison operator for complex numbers;

public:
    Complex(double re = 0.0, double im = 0.0);
        // Constructor for complex numbers with default parameters.

    // binary member function operators
    Complex& operator+=(const Complex& c);
        // Overloaded addition assignment operator.
        // Postcondition: Returned reference to calling object + c.

    Complex& operator-=(const Complex& c);
        // Overloaded subtraction assignment operator.
        // Postcondition: Returned reference to calling object - c.

    Complex& operator*=(const Complex& c);
        // Overloaded multiplication assignment operator.
        // Postcondition: Returned reference to calling object * c.

    Complex& operator/=(const Complex& c);
        // Overloaded division assignment operator.
        // Postcondition: Returned reference to calling object / c.

private:
    double m_Re, m_Im;
};
#endif // COMPLEX_H
