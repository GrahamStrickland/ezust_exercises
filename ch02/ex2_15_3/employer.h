// This is the interface of the class Employer,
// which represents an employer of a Person object.

#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <string>

using namespace std;

class Person;
class Position;

class Employer
{
public:
    Employer(string name, string market);
    // Constructor with arguments.
    // Postcondition: m_Name set to name, m_Market set to market.

    bool hire(Person& newHire, Position& pos);
    // Function to hire a new person.
    // Postcondition: newHire.set() called with arguments
    //  representing the calling object and pos.

    string toString() const;
    // Function to return a string representing the employer.
    // Postcondition: Returned a string including m_Name and
    //  m_Market.
private:
    string m_Name;
    string m_Market;
};
#endif // EMPLOYER_H
