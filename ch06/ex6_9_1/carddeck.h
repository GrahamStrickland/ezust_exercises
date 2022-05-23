#ifndef CARD_DECK_H
#define CARD_DECK_H

#include <QList>
#include <QString>
#include "card.h"
#include "cardhand.h"

class CardDeck
{
public:

    CardDeck();
        // Default constructor

    CardHand deal(int handSize);
        // Function to pick handSize Card objects from the deck.
        // Postcondition: Removed handSize elements from the deck
        //  and returned them as a CardHand object.

    QString toString() const;
        // Function to return a QString object representing the deck.
        // Postcondition: Returned QString.

    int getCardsLeft() const;
        // Function to return the number of cards left in the deck.
        // Postcondition: Returned an int value representing the number
        //  of cards left in the deck.

    void restoreDeck();
        // Function to restore the deck to its original size.
        // Postcondition: Deck contains 52 Card objects.

private:
    QList<Card*> m_Deck;
    int m_NumCards;
};
#endif // CARD_DECK_H
