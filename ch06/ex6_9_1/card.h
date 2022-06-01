#ifndef CARD_H
#define CARD_H

// This is the interface of the ADT Card which simulates a real-life
// playing card in a standard deck of 52 cards. It stores the face 
// number and suit of a card. The implementation is in the file
// "card.cpp"

#include <QString>
#include <QStringList>

class Card {
public:
    Card();
        // Default constructor.
        
    Card(int faceNbr, int suitNbr);
        // Constructor with arguments. faceNbr corresponds to
        //  0 = "A", 1 = "2", 2 = "3", ... , 10 = "J", 11 = "Q",
        //  12 = "K"; suitNbr corresponds to
        //  0 = "Diamonds", 1 = "Clubs", 2 = "Hearts", 3 = "Spades";

    QString toString() const;
        // Function to return a QString representing the number
        //  and suit of the Card object.

    QString getFace() const;
        // Function to return a QString representing the number
        //  of the Card object.

    QString getSuit() const;
        // Function to return a QString representing the suit
        //  of the Card object.

    int getValue() const;
        // Function to return the value of the Card object
        //  according to the rules of the game of bridge, i.e.
        //  Ace = 4, King = 3, Queen = 2, Jack = 1; all other 
        //  cards have zero value.
        // Postcondition: Returned m_Value;
private:
    int m_FaceNbr;
    int m_SuitNbr;
    static QStringList s_Faces;
    static QStringList s_Suits;
};
#endif // CARD_H
