// This is the interface for the ADT Fraction
// which implements a fraction using two private
// member functions; m_Numerator and m_Denominator
// with functions for arithmetic.

#ifndef FRACTION_H
#define FRACTION_H

#include <QString>

class Fraction
{
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

    Fraction add(const Fraction& other) const;
    // Function to add another fraction to the calling
    //  object.
    // Postcondition: Returned another Fraction object
    //  representing the calling object + other.

    Fraction subtract(const Fraction& other) const;
    // Function to subtract another fraction from the 
    //  calling object.
    // Postcondition: Returned another Fraction object
    //  representing the calling object - other.

    Fraction multiply(const Fraction& other) const;
    // Function to multiply another fraction by the
    //  calling object.
    // Postcondition: Returned another Fraction object
    //  representing the calling object * other.

    Fraction divide(const Fraction& other) const;
    // Function to divide the calling object by
    //  another fraction.
    // Postcondition: Returned another Fraction object
    //  representing the calling object / other.

    Fraction(int numerator = 1, int denominator = 1);
    // Constructor with default parameter.
private:
    int m_Numerator;    // int value to store numerator.
    int m_Denominator;  // int value to store denominator.
};
#endif // FRACTION_H
