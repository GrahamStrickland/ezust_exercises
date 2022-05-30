// This is the implementation of the ADT CardHand.
// The interface is in the file "cardhand.h"

#include <cassert>
#include <QDebug>
#include "cardhand.h"


CardHand::CardHand() : m_Value(0), m_NumCards(0)
{
    // Function body deliberately blank.
}

void CardHand::insertCard(Card* inserted)
{
    Card *newCard = inserted;

    // Add pointer to Card object.
    m_Hand.append(newCard);

    m_Value += newCard->getValue();
    m_NumCards++;
}

void CardHand::removeCard(Card* removed)
{
    // Check that hand is not empty.
    assert(!m_Hand.empty());

    Card *oldCard = removed;

    // Remove Card pointer and update number
    // and value.
    m_Hand.removeAll(oldCard);

    m_Value -= oldCard->getValue();
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
    QString handString = QString("");
    Card *currentCard;

    foreach(currentCard, m_Hand) {
        handString += '\n';
        handString += currentCard->toString();
    }
    handString += '\n';

    return handString;
}

CardHand::~CardHand()
{
    if (!m_Hand.empty()) {
        qDeleteAll(m_Hand);
        m_Hand.clear();
    }
}
