// This is the implementation of the class Employer.
// The interface is in the file employer.h

#include "employer.h"
#include "person.h"
#include "position.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Employer::Employer(QString name) :
    m_Name(name)
{
    srand(time(0));
}

bool Employer::hire(Person* newHire, Position* forPosition)
{
    bool hired;

    if (m_OpeningList.contains(forPosition)) { 
       hired = (rand() % 2 == 0) ? true : false;
       if (hired) {
           newHire->setPosition(this, forPosition);
           m_EmployeeList.append(newHire);
           return true;
       }
       else return false;
    }
    else return false;
}

QString Employer::toString() const
{
    return m_Name;
}

QList<Position*> Employer::findJobs() const
{
    return m_OpeningList;
}

void Employer::addPosition(Position* pos)
{
   m_OpeningList.append(pos); 
}
