// This is the interface for the class Person,
// which is composed of objects of type Employer
// and Position.

#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Employer;
class Position;

class Person
{
public:
    Person(string name);
    // Constructor with one argument.
    // Postcondition: m_Name = name.
    
    string toString() const;
    // Function to return the name of the Person object.
    // Postcondition: Returned m_Name;

    void setPosition(Employer newC, Position newP);
    // Function to set employer and position.
    // Postcondition: m_position set to newP, m_employer set to newC,
    //  m_Employed set to true.
    
    string getPosition() const;
    // Function to return a stringrepresenting the person's position.
    // Precondition: m_Employed == true.
    // Postcondition: If m_Employed == true, returned m_position.toString(),
    //  otherwise error message printed to console.

    string getEmployer() const;
    // Function to return a string representing the person's employer.
    // Precondition: m_Employed = true.
    // Postcondition: If m_Employed = true, returned m_employer.toSTring,
    //  otherwise error message printed to console.
private:
    string m_Name;
    bool m_Employed;
    Position *m_position;
    Employer *m_employer;

};
#endif // PERSON_H
