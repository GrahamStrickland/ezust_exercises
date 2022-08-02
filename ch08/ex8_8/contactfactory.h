#ifndef CONTACT_FACTORY_H
#define CONTACT_FACTORY_H

// This is the interface for the ADT contactFactory
// which generates random Contact objects.
// The implementation is in the file "contactFactory.cpp"

#include "contactlist.h"

class ContactFactory
{
public:
    ContactFactory();
        // Default ContactFactory constructor.

    void operator>>(ContactList* list);
        // Function to input a random Contact object into
        //  the given list.
        // Postcondition: randomly generated Contact object
        //  inserted into list.

    void createRandomContacts(ContactList* cl, int n=10);
        // Function to generate n random Contact objects and
        //  place them in cl.
        // Postcondition: cl filled with random Contact objects.

private:
    QString firstNames[3] = {"Bob", "Jim", "Dave"};
    QString lastNames[3] = {"Smith", "Jones", "Williams"};
    QString citiesFirst[4] = {"North", "East", "South", "West"};
    QString citiesLast[3] = {"Williamsburg", "Jonestown", "Smithfield"};
    QString streetNames[3] = {"Pleasant Avenue", "Main Street", "Queen\'s Street"};

    static int getRandomNumber(int min, int max);
        // Function to generate a random number in the range [min,max).
        // Postcondition: Returned a random number such that min <= 
        //  number < max.
};
#endif // CONTACT_FACTORY_H
