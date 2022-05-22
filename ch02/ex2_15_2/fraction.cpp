// This is the implementation of the ADT Fraction.
// The interface is in the file fraction.h

#include "fraction.h"
#include <QString>

using namespace std;

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
}

QString Fraction::toString() const
{
    return QString("%1/%2").arg(m_Numerator).arg(m_Denominator);
}

double Fraction::toDouble() const
{   
    return static_cast<double>(m_Numerator) / 
           static_cast<double>(m_Denominator);
}

Fraction Fraction::add(const Fraction& other) const
{
    Fraction temp;

    temp.set((m_Numerator * other.m_Denominator) + 
             (other.m_Numerator * m_Denominator),
             m_Denominator * other.m_Denominator);

    return temp;
}

Fraction Fraction::subtract(const Fraction& other) const
{
    Fraction temp;

    temp.set((m_Numerator * other.m_Denominator) -
             (other.m_Numerator * m_Denominator),
             m_Denominator * other.m_Denominator);

    return temp;
}

Fraction Fraction::multiply(const Fraction& other) const
{
    Fraction temp;

    temp.set(m_Numerator * other.m_Numerator,
             m_Denominator * other.m_Denominator);

    return temp;
}

Fraction Fraction::divide(const Fraction& other) const
{
    Fraction temp;

    temp.set(m_Numerator * other.m_Denominator,
             m_Denominator * other.m_Numerator);

    return temp;
}

Fraction::Fraction(int numerator, int denominator)
    : m_Numerator(numerator), m_Denominator(denominator)
{
    set(numerator, denominator);
}
