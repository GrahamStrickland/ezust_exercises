#include "complex.h"

using namespace std;

ostream& operator<<(ostream& out, const Complex& c) {
    out << '(' << c.m_Re << ',' << c.m_Im << ')';
    return out;
}

Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.m_Re + c2.m_Re, c1.m_Im + c2.m_Im);
}

Complex operator-(const Complex& c1, const Complex& c2) {
    return Complex(c1.m_Re - c2.m_Re, c1.m_Im - c2.m_Im);
}

Complex operator*(const Complex& c1, const Complex& c2) {
    return Complex(c1.m_Re*c2.m_Re - c1.m_Im*c2.m_Im,
            c1.m_Im*c2.m_Re + c1.m_Re*c2.m_Im);
}

Complex operator/(const Complex& c1, const Complex& c2) {
    return Complex(c1.m_Re*c2.m_Re + c1.m_Im*c2.m_Im,
            c1.m_Im*c2.m_Re - c1.m_Re*c2.m_Im);
}

bool operator!=(const Complex& c1, const Complex& c2)
{
    return c1.m_Re != c2.m_Re || c1.m_Im != c2.m_Im;
}

bool operator==(const Complex& c1, const Complex& c2)
{
    return c1.m_Re == c2.m_Re && c1.m_Im == c2.m_Im;
}
    
Complex::Complex(double re, double im) : m_Re(re), m_Im(im) {
    // Function body deliberately empty.
}

Complex& Complex::operator+=(const Complex& c) {
    m_Re += c.m_Re;
    m_Im += c.m_Im;

    return *this;
}

Complex& Complex::operator-=(const Complex& c) {
    m_Re -= c.m_Re;
    m_Im -= c.m_Im;

    return *this;
}

Complex& Complex::operator*=(const Complex& c) {
    m_Re = m_Re*c.m_Re - m_Im*c.m_Im;
    m_Im = m_Im*c.m_Re + m_Re*c.m_Im;

    return *this;
}

Complex& Complex::operator/=(const Complex& c) {
    m_Re = m_Re*c.m_Re + m_Im*c.m_Im;
    m_Im = m_Im*c.m_Re - m_Re*c.m_Im;

    return *this;
}
