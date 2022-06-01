// This is the implementation of the ADT Card.
// The interface is in the file "card.h"

#include <QChar>
#include "card.h"

// Declare static member variables.
QStringList Card::s_Faces = (QStringList() << "A" << "2" << "3" << "4" << "5" 
        << "6" << "7" << "8" << "9" << "T" << "J" << "Q" << "K");
QStringList Card::s_Suits = (QStringList() << "Diamonds" << "Clubs" << "Hearts" 
        << "Spades");

Card::Card() : m_FaceNbr(0), m_SuitNbr(0)
{
    // Function body deliberately blank.
}

Card::Card(int faceNbr, int suitNbr) : m_FaceNbr(faceNbr),
    m_SuitNbr(suitNbr)
{
    // Function body deliberately blank.
}

QString Card::toString() const
{
    return QString("%1 of %2")
                  .arg(getFace())
                  .arg(getSuit());
}

QString Card::getFace() const
{
    QString face = s_Faces[m_FaceNbr];
    char faceNum = face.at(0).toLatin1();

    switch(faceNum) {
    case 'A':
        face = QString("Ace");
        break;
    case 'T':
        face = QString("10");
        break;
    case 'J':
        face = QString("Jack");
        break;
    case 'Q':
        face = QString("Queen");
        break;
    case 'K':
        face = QString("King");
        break;
    }

    return face;
}

QString Card::getSuit() const
{
    return s_Suits[m_SuitNbr];
}

int Card::getValue() const
{
    // Assign value depending on face number.
    int value;

    switch(m_FaceNbr) {
    case 0:
        value = 4;
        break;
    case 12:
        value = 3;
        break;
    case 11:
        value = 2;
        break;
    case 10:
        value = 1;
        break;
    default:
        value = 0;
        break;
    }

    return value;
}
