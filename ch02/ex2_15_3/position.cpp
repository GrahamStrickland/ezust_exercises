// This is the implementation of the class Position.
// The interface is in the file position.h

#include "position.h"

using namespace std;

Position::Position(string name, string description) :
    m_Name(name), m_Description(description)
{
    // Function body intentionally blank.
}

string Position::toString() const
{
    return m_Name + " - " + m_Description;
}
