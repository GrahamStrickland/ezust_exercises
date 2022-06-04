// This is the implementation of the ADT CardDeck.
// The interface is in the file "carddeck.h".

#include <cstdlib>
#include <ctime>
#include <QTextStream>
#include "card.h"
#include "carddeck.h"

const int NUM_SUITS = 4;
const int NUM_FACES = 13;

QTextStream cout(stdout);

CardDeck::CardDeck() : m_NumCards(0)
{
    // Generate all cards in standard deck.
    Card *newCard = 0;

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
    Card *newCard = 0;
    int cardNum;

    // Seed random number generator.
    srandom(time(0));

    while (m_NumCards > 0 && hand.getNumCards() < handSize) {
        cardNum = random() % m_NumCards;
        if (m_Deck.at(cardNum)) {
            newCard = m_Deck.takeAt(cardNum);
            hand.insertCard(newCard);
            m_NumCards--;
        }
    }

    if (m_NumCards == 0)
        cout << "No cards left in deck!" << endl;

    return hand;
}

QString CardDeck::toString() const
{
    // Create QString and append all cards.
    Card *currentCard = 0;
    QString deckString = QString("");

    foreach(currentCard, m_Deck) {
        deckString += '\n';
        deckString += currentCard->toString();
    }
    deckString += '\n';

    return deckString;
}

int CardDeck::getCardsLeft() const
{
    return m_NumCards;
}

void CardDeck::restoreDeck()
{
    Card *newCard = 0;

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
