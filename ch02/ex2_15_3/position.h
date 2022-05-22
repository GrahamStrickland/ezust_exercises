// This is the interface for the class Position,
// which represents the position of a Person object.

#ifndef POSITION_H
#define POSITION_H

#include <string>

using namespace std;

class Position
{
public:
    Position(string name, string description);
    // Constructor with arguments.
    // Postcondition: Object initialized with m_Name set to name,
    //  and m_Description set to description.

    string toString() const;
    // Function to return a string representing the position.
    // Postcondition: Returned a string including m_Name and m_Description.
private:
    string m_Name;
    string m_Description;
};
#endif // POSITION_H
