#include <cassert>
#include "cardhand.h"

CardHand::CardHand() : m_Value(0), m_NumCards(0)
{
    // Function body deliberately blank.
}

void CardHand::insertCard(const Card& inserted)
{
    m_Hand.append(&inserted);

    m_Value += inserted->getValue();
    m_NumCards++;
}

void CardHand::removeCard(const Card& removed)
{
    assert(!m_Hand.empty());

    m_Hand.removeAll(&removed);

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
    QString hand = QString("");

    foreach(Card *current, m_Hand) {
        hand += current->toString();
        hand += " ";
    }

    return hand;
}
