#include <cstdlib>
#include <ctime>
#include "card.h"
#include "carddeck.h"

const int NUM_SUITS = 4;
const int NUM_FACES = 13;

CardDeck::CardDeck() m_NumCards(0)
{
    Card *newCard;

    for (int suitNbr = 0; suitNbr < NUM_SUITS; ++suitNbr) 
    {
        for (int faceNbr = 0; faceNbr < NUM_FACES; ++faceNbr) 
        {
            newCard = new Card(faceNbr, suitNbr);
            m_Deck.append(&newCard);
            m_NumCards++;
        }
    }
}

CardHand CardDeck::deal(int handSize)
{
    CardHand hand;
    int cardNum;

    srandom(time(0));

    while (hand.getNumCards < handSize) {
        cardNum = random() % (NUM_SUITS * NUM_FACES);
        hand.insertCard(m_Deck.takeAt(cardNum));
    }

    return hand;
}

QString CardDeck()::toString() const
{
    QString deck = QString("");

    foreach(Card *current, m_Deck) {
        deck += current->toString();
        deck += '\n';
    }

    return deck;
}

int CardDeck::getCardsLeft() const
{
    return m_NumCards;
}

void CardDeck::restoreDeck()
{
    Card *newCard;

    for (int suitNbr = 0; suitNbr < NUM_SUITS; ++suitNbr) 
    {
        for (int faceNbr = 0; faceNbr < NUM_FACES; ++faceNbr) 
        {
            newCard = new Card(faceNbr, suitNbr);
            m_Deck.append(&newCard);
            m_NumCards++;
        }
    }
}
