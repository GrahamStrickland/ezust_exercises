#ifndef CONTACT_H
#define CONTACT_H

// This is the interface for the ADT Contact, which represents a contact to be included
// in a ContactList object. The implementation is in the file "contact.cpp"

#include <QObject>
#include <QString>

class Contact: public QObject
{
    Q_OBJECT
public:
    explicit Contact(int cat = 0, QString first = "", QString last = "",
            QString add = "", QString zip = "", QString cty = "",
            QString num = "", QObject* parent = 0);
        // Constructor for objects of type Contact, default values set to "" or 0
        //  (for category).
    
    bool operator==(const Contact& otherContact) const;
        // Overloaded operator function to check for equality between Contact 
        //  objects.
        // Postcondition: Returned true if toString() ==
        //  otherContact.toString().

    QString toString() const;
        // Function to return a QString representing the Contact object.
        // Postcondition: Returned a QString with all private member variables
        //  included.

    QString getName() const;
        // Function to return the name of the contact.
        // Postcondition: Returned firstName + lastName conactenated as a single
        //  QString.

    QString getNumber() const;
        // Function to return the phone number of the contact.
        // Postcondition: Returned phoneNumber.

    QString getAddress() const;
        // Function to return the full address of the contact.
        // Postcondition: Returned QString with all address details concatenated.
        
    int getCategory() const;
        // Function to return the category of the contact.
        // Postcondition: Returned category.

    virtual ~Contact();
        //Destructor.
        
private:
    int m_Category;
    QString m_FirstName;
    QString m_LastName;
    QString m_StreetAddress;
    QString m_ZipCode;
    QString m_City;
    QString m_PhoneNumber;
};
#endif // CONTACT_H
