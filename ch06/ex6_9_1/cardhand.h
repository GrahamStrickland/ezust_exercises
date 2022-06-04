#ifndef CARD_HAND_H
#define CARD_HAND_H

// This is the interface of the ADT CardHand which stores a
// randomly generated QList of Card objects. It is thus an
// aggregation of the Card ADT. The implemtation is in the file
// "cardhand.h"

#include <QString>
#include <QList>
#include "card.h"

class CardHand {
public:
    CardHand();
        // Default constructor

    void insertCard(Card* inserted);
        // Function to insert a Card object into the CardHand object.

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

    ~CardHand();
        // Destructor

private:
    QList<Card*> m_Hand;
    int m_Value;
    int m_NumCards;
};
#endif // CARD_HAND_H
