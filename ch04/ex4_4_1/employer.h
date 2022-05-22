#ifndef EMPLOYER_H
#define EMPLOYER_H

// This is the interface of the class Employer,
// which represents an employer of a Person object.

#include <QString>
#include <QList>

using namespace std;

class Person;
class Position;

class Employer
{
public:
    Employer(QString name);
    // Constructor with argument.
    // Postcondition: m_Name set to name.

    bool hire(Person* newHire, Position* pos);
    // Function to hire a new person.
    // Postcondition: newHire.set() called with arguments
    //  representing the calling object and pos.

    QString toString() const;
    // Function to return a QString representing the employer.
    // Postcondition: Returned a QString including m_Name and
    //  m_Market.

    QList<Position*> findJobs() const;
    // Function to return a list of available jobs from this employer.
    // Postcondition: Returned m_OpeningList.

    void addPosition(Position* pos);
    // Function to add a Position managed by this Employer.
    // Postcondition: pos added to m_OpeningList;

private:
    QString m_Name;
    QList<Person*> m_EmployeeList;
    QList<Position*> m_OpeningList;
};
#endif // EMPLOYER_H
