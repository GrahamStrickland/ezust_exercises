// This is the implementation of the ADT Contact,
// the interface is in the file "contact.h"

#include "contact.h"

bool Contact::operator==(const Contact& otherContact) const
{
    return toString() == otherContact.toString();
}

Contact::Contact(int cat, QString first, QString last,
                QString add, QString zip, QString cty,
                QString num, QObject* parent) 
    : QObject(parent), m_Category(cat), m_FirstName(first),
    m_LastName(last), m_StreetAddress(add), m_ZipCode(zip), 
    m_City(cty), m_PhoneNumber(num)
{
    // Function body deliberately blank.
}

QString Contact::toString() const
{
    QString contactStr = 
    QString("Category: %1\nFirst Name: %2\nLast Name: %3\n")
        .arg(m_Category)
        .arg(m_FirstName)
        .arg(m_LastName)
        .append(
    QString("Street Address: %4\nZip Code %5\nCity: %6\nPhone Number: %7\n")
        .arg(m_StreetAddress)
        .arg(m_ZipCode)
        .arg(m_City)
        .arg(m_PhoneNumber));
    return contactStr;
}

QString Contact::getName() const
{
    return QString("%2, %1")
        .arg(m_FirstName)
        .arg(m_LastName);
}

QString Contact::getNumber() const
{
    return m_PhoneNumber;
}

QString Contact::getAddress() const
{
    return QString("%1, %2, %3")
        .arg(m_StreetAddress)
        .arg(m_ZipCode)
        .arg(m_City);
}

int Contact::getCategory() const
{
    return m_Category;
}

Contact::~Contact()
{
    //Function body deliberately blank.
}
