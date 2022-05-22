#ifndef PERSON_H
#define PERSON_H

// This is the interface for the class Person,
// which is composed of objects of type Employer
// and Position.

#include <QString>
#include <QList>

using namespace std;

class Employer;
class Position;

class Person
{
public:
    Person(QString name);
    // Constructor with one argument.
    // Postcondition: m_Name = name.
    
    QString getName() const;
    // Function to return the name of the Person object.
    // Postcondition: Returned m_Name;

    bool apply(Position* pos);
    // Function to call Employer::hire().
    // Postcondition: Employer::hire() called for Employer related to
    //  Position.
    
    Position* getPosition() const;
    // Function to return a stringrepresenting the person's position.
    // Precondition: m_Employed == true.
    // Postcondition: If m_Employed == true, returned m_position.toString(),
    //  otherwise error message printed to console.

    Employer* getEmployer() const;
    // Function to return a string representing the person's employer.
    // Precondition: m_Employed = true.
    // Postcondition: If m_Employed = true, returned m_employer.toString,
    //  otherwise error message printed to console.

    void setPosition(Employer* empl, Position* pos);
    // Function to set the position of the Person objec.
    // Postcondition: m_employer = empl; m_position = pos;

private:
    QString m_Name;
    bool m_Employed;
    Employer* m_employer;
    Position* m_position;
    static QList<Person*> s_unemploymentLine;
};
#endif // PERSON_H
