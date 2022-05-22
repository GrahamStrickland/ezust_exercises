#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

// This is the interface for the ADT ContactList that defines
// a list of Contact objects inherited from the QList class.
// The implementation is in the file contactList.cpp

#include "contact.h"
#include <QList>
#include <QStringList>

class ContactList
{
public:
    ContactList();
        // Default constructor function.
        // Postcondition: Empty list containing NULL pointer initialized;
        //  length = 0.

    ContactList(QList<Contact> list);
        // Constructor function with list parameter.
        // Postcondition: ContactList initialized with m_ContactList set
        //  to list.

    ContactList(unsigned int length);
        // Constructor function with int parameter.
        // Postcondition: m_length set to length and m_ContactList initialized
        //  and memory reserved of size m_length.

    void add(const Contact& c);
        // Function to add a contact to the contact list.
        // Postcondition: m_length++ and contact added to m_ContactList.

    void remove(const Contact& c);
        // Function to remove a contact from the contact list.
        // Postcondition: Contact c removed from m_ContactList and m_ContactList
        //  decremented by number of occurrences of c.

    QStringList getPhoneList(int cat) const;
        // Function to return a list of names and phone numbers matching the 
        //  given category.
        // Postcondition: Returned QStringList object with all names and phone
        //  numbers matching cat separated by '\t'.

    QStringList getMailingList(int cat) const;
        // Function to return a list of names and addresses matching the given
        //  category.
        // Postcondition: Returned QStringList object with all names and addresses
        //  matching cat separated by '\t'.
    ~ContactList();
        // Destructor function.

private:
    unsigned int m_length;
    QList<Contact> m_ContactList;
};
#endif // CONTACT_LIST_H
