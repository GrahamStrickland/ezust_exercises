// This is the implementation of the class Person.
// The interface is in the file person.h

#include "person.h"
#include "position.h"
#include "employer.h"
#include <iostream>

using namespace std;

Person::Person(string name) : m_Name(name)
{
    m_Employed = false;
}

string Person::toString() const
{
    return m_Name;
}

void Person::setPosition(Employer newC, Position newP)
{
    m_Employed = true;
    m_employer = &newC;
    m_position = &newP;
}

string Person::getPosition() const
{
    if (m_Employed) return m_position->toString();
    else return "This pathetic wretch has no position!";
}

string Person::getEmployer() const
{
    if (m_Employed) return m_employer->toString();
    else return "This virulent pond-scum has no employer!";
}
