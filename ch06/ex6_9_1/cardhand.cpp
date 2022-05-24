#include "cardhand.h"

CardHand::CardHand() : m_Value(0)
{
    // Function body deliberately blank.
}

void CardHand::insertCard(const Card& inserted)
{
    m_Hand.append(inserted);

    m_Value += inserted.getValue();
}

void CardHand::removeCard(const Card& removed)
{
    m_Hand.removeAll(removed);

    m_Value -= removed.getValue();
}

int CardHand::getValue() const
{
    return m_Value;
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
