#ifndef CARD_HAND_H
#define CARD_HAND_H

#include <QString>
#include <QList>
#include "card.h"

class CardHand {
public:
    CardHand();
        // Default constructor

    void insertCard(const Card &inserted);
        // Function to insert a Card object into the CardHand object.

    void removeCard(const Card &removed);
        // Function to remove a Card object from the CardHand object.
        
    int getValue() const;
        // Function to return the card value of the CardHand
        //  object according to the rules of the game of bridge,
        //  i.e. Ace = 4, King = 3, Queen = 2, Jack = 1; all other
        //  cards have zero value.
        // Postcondition: Returned m_Value.

    int getNumCards() const;
        // Function to return the number of cards in the CardHand object.

    QString toString() const;
        // Function to return a QString representation of the hand.
private:
    QList<Card*> m_Hand;
    int m_Value;
    int m_NumCards;
};
#endif // CARD_HAND_H
