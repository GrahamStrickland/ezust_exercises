// This is the implementation of the ADT ContactList.
// The interface is in the file contactList.h

#include "contactList.h"

using namespace std;

ContactList::ContactList()
    : m_length(0)
{
   m_ContactList.reserve(m_length);
}

ContactList::ContactList(QList<Contact> list) 
    : m_length(list.size())
{
    m_ContactList.reserve(m_length);
}

ContactList::ContactList(unsigned int length)
    : m_length(length)
{
    m_ContactList.reserve(m_length);
}

void ContactList::add(const Contact& c)
{
    m_length++;
    m_ContactList.append(c);
}

void ContactList::remove(const Contact& c)
{
    unsigned int num = m_ContactList.removeAll(c);
    m_length -= num;
}

QStringList ContactList::getPhoneList(int cat) const
{
    QStringList phoneList;

    foreach (const Contact &contact, m_ContactList) {
        if (contact.getCategory() == cat)
            phoneList << QString("%1\t%2")
                .arg(contact.getName())
                .arg(contact.getNumber());
    }

    return phoneList;
}

QStringList ContactList::getMailingList(int cat) const
{
    QStringList mailingList;

    foreach (const Contact &contact, m_ContactList) {
        if (contact.getCategory() == cat)
            mailingList << QString("%1\t%2")
                .arg(contact.getName())
                .arg(contact.getAddress());
    }

    return mailingList;
}

ContactList::~ContactList()
{
    m_ContactList.clear();
}
