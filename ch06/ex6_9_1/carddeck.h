#ifndef CARD_DECK_H
#define CARD_DECK_H

// This is the interface of the ADT CardDeck, which simulates a standard
// deck of 52 cards using a composition of Card objects stored in a
// QList object. The implementation is in the file "carddeck.cpp"
#include <QList>
#include <QString>
#include "card.h"
#include "cardhand.h"

class CardDeck : public QList<Card*> 
{
public:
    CardDeck();
        // Default constructor
        // Postcondition: m_NumCards = 52; m_Deck points to a full
        //  deck of cards;

    CardHand deal(int handSize);
        // Function to pick handSize Card objects from the deck.
        // Postcondition: Removed handSize elements from the deck
        //  and returned them as a CardHand object.

    QString toString() const;
        // Function to return a QString object representing the deck.

    int getCardsLeft() const;
        // Function to return the number of cards left in the deck.
        // Postcondition: Returned m_NumCards;

    void restoreDeck();
        // Function to restore the deck to its original size.
        // Postcondition: Deck restored to 52 cards of correct
        //  number/suite.

    ~CardDeck();
        // Destructor
private:
    QList<Card*> m_Deck;
    int m_NumCards;
};
#endif // CARD_DECK_H
