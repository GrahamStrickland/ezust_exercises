// This is the implementation of the ADT CardDeck.
// The interface is in the file "carddeck.h".

#include <cstdlib>
#include <ctime>
#include "card.h"
#include "carddeck.h"

const int NUM_SUITS = 4;
const int NUM_FACES = 13;

CardDeck::CardDeck() : m_NumCards(0)
{
    // Generate all cards in standard deck.
    Card *newCard;

    for (int suitNbr = 0; suitNbr < NUM_SUITS; ++suitNbr) 
    {
        for (int faceNbr = 0; faceNbr < NUM_FACES; ++faceNbr) 
        {
            newCard = new Card(faceNbr, suitNbr);
            m_Deck.append(newCard);
            m_NumCards++;
        }
    }
}

CardHand CardDeck::deal(int handSize)
{
    CardHand hand;
    int cardNum;

    // Seed random number generator.
    srandom(time(0));

    while (hand.getNumCards() < handSize) {
        cardNum = random() % (NUM_SUITS * NUM_FACES);
        if (m_Deck[cardNum]) {
            hand.insertCard(m_Deck.takeAt(cardNum));
        }
    }

    return hand;
}

QString CardDeck::toString() const
{
    // Create QString and append all cards.
    QString deck = QString("");

    foreach(Card* current, m_Deck) {
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

    // Clear deck and add all cards.
    m_Deck.clear();

    for (int suitNbr = 0; suitNbr < NUM_SUITS; ++suitNbr) 
    {
        for (int faceNbr = 0; faceNbr < NUM_FACES; ++faceNbr) 
        {
            newCard = new Card(faceNbr, suitNbr);
            m_Deck.append(newCard);
            m_NumCards++;
        }
    }
}

CardDeck::~CardDeck()
{
    if (!m_Deck.empty()) {
        qDeleteAll(m_Deck);
        m_Deck.clear();
    }
}
