// This is the implementation of the class Position.
// The interface is in the file position.h

#include "position.h"
#include "employer.h"

using namespace std;

Position::Position(QString name, QString description, Employer* empl) :
    m_Name(name), m_Description(description), m_employer(empl)
{
    m_employer->addPosition(this);
}

QString Position::toString() const
{
    return QString(m_Name + " - " + m_Description);
}

Employer* Position::getEmployer() const
{
    return m_employer;
}

void Position::setEmployer(Employer* empl)
{
    m_employer = empl;
}
