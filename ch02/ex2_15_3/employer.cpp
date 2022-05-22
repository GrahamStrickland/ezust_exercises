// This is the implementation of the class Employer.
// The interface is in the file employer.h

#include "employer.h"
#include "person.h"
#include "position.h"
#include <iostream>

using namespace std;

Employer::Employer(string name, string market) :
    m_Name(name), m_Market(market)
{
    // Function body intentionally blank.
}

bool Employer::hire(Person& newHire, Position& pos)
{
   newHire.setPosition(*this, pos);
   return true;
}

string Employer::toString() const
{
    return m_Name + " - " + m_Market;
}
