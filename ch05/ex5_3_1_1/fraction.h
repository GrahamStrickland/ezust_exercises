#ifndef FRACTION_H
#define FRACTION_H

// This is the interface for the ADT Fraction
// which implements a fraction using two private
// member functions; m_Numerator and m_Denominator
// with functions for arithmetic.

#include <QString>
#include <iostream>
#include <fstream>

class Fraction
{
    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
        // Overloaded addition operator.
        // Postcondition: Returned new Fraction object representing
        //  f1 + f2.

    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
        // Overloaded subtraction operator.
        // Postcondition: Returned new Fraction object representing
        //  f1 - f2.

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
        // Overloaded multiplication operator.
        // Postcondition: Returned new Fraction object representing
        //  f1 * f2.

    friend Fraction operator/(const Fraction& f1, const Fraction& f2);
        // Overloaded division operator.
        // Postcondition: Returned new Fraction object representing
        //  f1 / f2.

    friend bool operator==(const Fraction& f1, const Fraction& f2);
        // Overloaded equality comparison operator.
        // Postcondition: Returned true if f1 == f2; otherwise false.

    friend bool operator!=(const Fraction& f1, const Fraction& f2);
        // Overloaded inequality comparison operator.
        // Postcondition: Returned true if f1 != f2; otherwise false.

public:
    void set(int numerator, int denominator);
        // Function to set the value of the fraction.
        // Postcondition: m_Numerator = numerator;
        //  m_Denominator = denominator.

    QString toString() const;
        // Function to return a string representing
        //  the fraction.
        // Postcondition: Returned QString object of the form
        //  numerator / denominator.

    double toDouble() const;
        // Function to return a decimal representation of
        //  the fraction.
        // Postcondition: Returned double value equivalent
        //  of Fraction.

    Fraction(int numerator = 1, int denominator = 1);
        // Constructor with default parameter.
    
    Fraction(double dec);
        // Constructor with decimal parameter.
        // Postcondition: Fraction set to equivalent fraction of dec.
        
private:
    int m_Numerator;    // int value to store numerator.
    int m_Denominator;  // int value to store denominator.
};
#endif // FRACTION_H
