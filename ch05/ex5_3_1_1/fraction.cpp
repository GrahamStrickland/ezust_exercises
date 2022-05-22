// This is the implementation of the ADT Fraction.
// The interface is in the file fraction.h

#include "fraction.h"
#include <cmath>

using namespace std;

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
    Fraction temp;

    temp.set((f1.m_Numerator * f2.m_Denominator) + 
             (f2.m_Numerator * f1.m_Denominator),
             f1.m_Denominator * f2.m_Denominator);

    return temp;
}

Fraction operator-(const Fraction& f1, const Fraction& f2)
{
    Fraction temp;

    temp.set((f1.m_Numerator * f2.m_Denominator) -
             (f2.m_Numerator * f1.m_Denominator),
             f1.m_Denominator * f2.m_Denominator);

    return temp;
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    Fraction temp;

    temp.set(f1.m_Numerator * f2.m_Numerator,
             f1.m_Denominator * f2.m_Denominator);

    return temp;
}

Fraction operator/(const Fraction& f1, const Fraction& f2)
{
    Fraction temp;

    temp.set(f1.m_Numerator * f2.m_Denominator,
             f1.m_Denominator * f2.m_Numerator);

    return temp;
}

bool operator==(const Fraction& f1, const Fraction& f2)
{
    return f1.m_Numerator == f2.m_Numerator &&
        f1.m_Denominator == f2.m_Denominator;
}

bool operator!=(const Fraction& f1, const Fraction& f2)
{
    return f1.m_Numerator != f2.m_Numerator ||
        f1.m_Denominator != f2.m_Denominator;
}

void Fraction::set(int numerator, int denominator)
{   
    m_Numerator = numerator;
    m_Denominator = denominator;

    // Simplify negatives.
    if ((m_Numerator < 0 && m_Denominator < 0) ||
         m_Denominator < 0) {
        m_Numerator = -m_Numerator;
        m_Denominator = -m_Denominator;
    }

    // Store 0 fractions in lowest form.
    if (m_Numerator == 0)
        m_Denominator = 1;
    else {  // Check for common denominator and store in
            // lowest form.
        int max;    // Calculate maximum.
        if (m_Numerator < 0) max = -m_Numerator;
        else max = m_Numerator;

        if (m_Denominator > max) max = m_Denominator; 

        // Search for common denominator.
        if (m_Numerator > 0)
            for (int i = 2; i < max/2 + 1; ++i)
            {
                if (m_Numerator % i == 0 && m_Denominator % i == 0) {
                    m_Numerator /= i;
                    m_Denominator /= i;
                }
            }
        else
            for (int i = -2; i > -max/2 - 1; --i)
            {
                if (m_Numerator % i == 0 && m_Denominator % i == 0) {
                    m_Numerator /= i;
                    m_Denominator /= i;
                }
            }

    }

    // Check again for negative denominator, positive numerator.
    if (m_Denominator < 0 && m_Numerator > 0) {
        m_Numerator = -m_Numerator;
        m_Denominator = -m_Denominator;
    }
}

QString Fraction::toString() const
{
    if (m_Numerator == 0)
        return QString("%1").arg(0);
    else if (m_Denominator == 1)
        return QString("%1").arg(m_Numerator);
    else
        return QString("%1/%2").arg(m_Numerator).arg(m_Denominator);
}

double Fraction::toDouble() const
{   
    return static_cast<double>(m_Numerator) / 
           static_cast<double>(m_Denominator);
}

Fraction::Fraction(int numerator, int denominator)
    : m_Numerator(numerator), m_Denominator(denominator)
{
    set(numerator, denominator);
}

Fraction::Fraction(double dec)
{
    double numerator = dec;
    int denominator = 1;

    while (abs(numerator) - floor(abs(numerator)) != 0.0)
    {
        numerator *= 10.0;
        denominator *= 10;
    }

    set(static_cast<int>(numerator), denominator);
}
