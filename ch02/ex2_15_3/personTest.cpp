// This is a driver program to test the classes Person,
// Employer, and Position.

#include "person.h"
#include "employer.h"
#include "position.h"
#include <iostream>

int main()
{
    using namespace std;

    // Test Employer constructor.
    Employer employer1("StarFleet Federation", "Intergalactic"),
             employer2("Borg", "Cyberspace");

    // Test Person constructor.
    Person person1("Jean-Luc Picard"), person2("Wesley Crusher");

    // Test Position constructor.
    Position position1("Captain", "Commander in Chief of the fleet"),
             position2("Worm", "Sniveling worm boy");

    // Test setPosition()
    person1.setPosition(employer1, position1);
    person2.setPosition(employer2, position2);

    // Print details of each Person object.
    cout << "person1:\n" << person1.toString() << endl
         << "Employer: " << person1.getEmployer() << endl
         << "Position: " << person1.getPosition() << endl
         << "\nperson2:\n" << person2.toString() << endl
         << "Employer: " << person2.getEmployer() << endl
         << "Position: " << person2.getPosition() << endl;

    return 0;
}
