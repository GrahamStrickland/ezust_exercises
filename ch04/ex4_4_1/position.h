#ifndef POSITION_H
#define POSITION_H

// This is the interface for the class Position,
// which represents the position of a Person object.

#include <QString>

using namespace std;

class Employer;

class Position
{
public:
    Position(QString name, QString desc, Employer* empl);
    // Constructor with arguments.
    // Postcondition: Object initialized with m_Name set to name,
    //  and m_Description set to description.

    QString toString() const;
    // Function to return a QString representing the position.
    // Postcondition: Returned a QString including m_Name and m_Description.
    
    Employer* getEmployer() const;
    // Function to return the Employer who maintains this position.
    // Postcondition: Returned m_employer.

    void setEmployer(Employer* empl);
    // Function to set the Employer who maintains this Position.
    // Postcondition: m_Employer set to empl.

private:
    QString m_Name;
    QString m_Description;
    Employer* m_employer;
};
#endif // POSITION_H
