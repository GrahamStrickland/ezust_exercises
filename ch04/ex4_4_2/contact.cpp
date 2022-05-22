// This is the implementation of the ADT Contact,
// the interface is in the file "contact.h"

#include "contact.h"

using namespace std;

bool Contact::operator==(const Contact& otherContact) const
{
    return toString() == otherContact.toString();
}

Contact::Contact(int cat, QString first, QString last,
                QString add, QString zip, QString cty,
                QString num) : category(cat), firstName(first),
                    lastName(last), streetAddress(add), zipCode(zip),
                    city(cty), phoneNumber(num)
{
    // Function body deliberately blank.
}

QString Contact::toString() const
{
    return QString("Category: %1\nFirst Name: %2\nLast Name: %3\nStreet Address: %4\nZip Code %5\nCity: %6\nPhone Number: %7\n")
        .arg(category)
        .arg(firstName)
        .arg(lastName)
        .arg(streetAddress)
        .arg(zipCode)
        .arg(city)
        .arg(phoneNumber);
}

QString Contact::getName() const
{
    return QString("%2, %1").arg(firstName).arg(lastName);
}

QString Contact::getNumber() const
{
    return phoneNumber;
}

QString Contact::getAddress() const
{
    return QString("%1, %2, %3").arg(streetAddress).arg(zipCode).arg(city);
}

int Contact::getCategory() const
{
    return category;
}
