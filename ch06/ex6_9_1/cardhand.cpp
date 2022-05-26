// This is the implementation of the ADT CardHand.
// The interface is in the file "cardhand.h"

#include <cassert>
#include "cardhand.h"

CardHand::CardHand() : m_Value(0), m_NumCards(0)
{
    // Function body deliberately blank.
}

void CardHand::insertCard(Card* inserted)
{
    // Add pointer to Card object.
    m_Hand.append(inserted);

    m_Value += inserted->getValue();
    m_NumCards++;
}

void CardHand::removeCard(Card* removed)
{
    // Check that hand is not empty.
    assert(!m_Hand.empty());

    // Remove Card pointer and update number
    // and value.
    m_Hand.removeAll(removed);

    m_Value -= removed->getValue();
    m_NumCards--;
}

int CardHand::getValue() const
{
    return m_Value;
}

int CardHand::getNumCards() const
{
    return m_NumCards;
}

QString CardHand::toString() const
{
    // Generate QString for each Card object stored
    // in hand.
    QString hand = QString("");

    foreach(Card* current, m_Hand) {
        hand += current->toString();
        hand += " ";
    }

    return hand;
}

CardHand::~CardHand()
{
    if (!m_Hand.empty()) {
        qDeleteAll(m_Hand);
        m_Hand.clear();
    }
}
