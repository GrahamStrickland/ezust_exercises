// This is the implementation of the ADT ContactList.
// The interface is in the file contactList.h

#include "contactlist.h"

ContactList::ContactList(QObject* parent)
    : QObject(parent), m_Length(0)
{
   m_ContactList.reserve(m_Length);
}

ContactList::ContactList(QList<Contact> list, QObject* parent) 
    : QObject(parent), m_Length(list.size())
{
    m_ContactList.reserve(m_Length);
}

ContactList::ContactList(unsigned int length, QObject* parent)
    : QObject(parent), m_Length(length)
{
    m_ContactList.reserve(m_Length);
}

void ContactList::add(Contact* const c)
{
    m_Length++;
    m_ContactList.append(c);
}

void ContactList::remove(Contact* const c)
{
    unsigned int num = m_ContactList.removeAll(c);
    m_Length -= num;
}

QStringList ContactList::getPhoneList(int cat) const
{
    QStringList phoneList;

    foreach (const Contact* contact, m_ContactList) {
        if (contact->getCategory() == cat)
            phoneList << QString("%1\t%2")
                .arg(contact->getName())
                .arg(contact->getNumber());
    }

    return phoneList;
}

QStringList ContactList::getMailingList(int cat) const
{
    QStringList mailingList;

    foreach (const Contact* contact, m_ContactList) {
        if (contact->getCategory() == cat)
            mailingList << QString("%1\t%2")
                .arg(contact->getName())
                .arg(contact->getAddress());
    }

    return mailingList;
}

ContactList::~ContactList()
{
    qDeleteAll(m_ContactList);
    m_ContactList.clear();
}
