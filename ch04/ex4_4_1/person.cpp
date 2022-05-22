// This is the implementation of the class Person.
// The interface is in the file person.h

#include "person.h"
#include "position.h"
#include "employer.h"
#include <QTextStream>

QList<Person*> Person::s_unemploymentLine;

QTextStream cout(stdout);

using namespace std;

Person::Person(QString name) : m_Name(name)
{
    m_Employed = false;
    s_unemploymentLine.append(this);
    Employer noEmpl("Unemployed");
    Position noPos("Unemployed", "No job", &noEmpl);
    m_employer = &noEmpl;
    m_position = &noPos;
}

QString Person::getName() const
{
    return m_Name;
}

bool Person::apply(Position* pos)
{
    bool hired = pos->getEmployer()->hire(this, pos);
    if (hired) {
        m_position = pos;
        m_employer = pos->getEmployer();
        s_unemploymentLine.removeAll(this);
        m_Employed = true;
    }
    return hired;
}

Position* Person::getPosition() const
{
    if (!m_Employed) 
        cout << endl << getName() << " is not currently employed.\n";
    return m_position;
}

Employer* Person::getEmployer() const
{
    if (!m_Employed) 
        cout << endl << getName() << " is not currently employed.\n";
    return m_employer;
}

void Person::setPosition(Employer* empl, Position* pos)
{
    m_Employed = true;
    m_employer = empl;
    m_position = pos;
    s_unemploymentLine.removeAll(this);
}
