// Test program for the classes Person, Employer, and Position.
#include <QTextStream>
#include "person.h"
#include "employer.h"
#include "position.h"

using namespace std;

int main()
{   // Declare output stream to test objects.
    QTextStream cout(stdout);

    // Declare objects with QString data.
    Employer empl1("Galactic Empire"), empl2("Rebel Forces");
    Person pers1("Darth Vader"), pers2("C3PO"), pers3("Data");
    Position pos1("Tie Fighter Pilot",
            "Fastest pilots in the Galactic Empire fleet",
            &empl1),
             pos2("Protocol Android",
            "Most annoying droids in the rebel forces",
            &empl2),
             pos3("Captain",
            "Captain of a Star Destroyer",
            &empl1);

    // Test apply() function and output data for each object.
    bool hired;

    hired = pers1.apply(&pos1);
    if (hired) cout << pers1.getName() << " is employed by " 
                    << pers1.getEmployer()->toString()
                    << " as a " << pers1.getPosition()->toString()
                    << endl << endl;

    hired = pers2.apply(&pos2);
    if (hired) cout << pers2.getName() << " is employed by "
                    << pers2.getEmployer()->toString()
                    << " as a " << pers2.getPosition()->toString()
                    << endl << endl;

    hired = pers3.apply(&pos3);
    if (hired) cout << pers3.getName() << " is employed by "
                    << pers3.getEmployer()->toString()
                    << " as a " << pers3.getPosition()->toString()
                    << endl << endl;

    return 0;
}
