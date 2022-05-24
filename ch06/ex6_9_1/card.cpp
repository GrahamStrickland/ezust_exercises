#include "card.h"

// Declare static member variables.
QStringList s_Faces = (QStringList() << "A" << "2" << "3" << "4" << "5" 
        << "6" << "7" << "8" << "9" << "T" << "J" << "Q" << "K");
QStringList s_Suits = (QStringList() << "Diamonds" << "Clubs" << "Hearts" 
        << "Spades";

Card::Card(int faceNbr, int suitNbr) : m_FaceNbr(faceNbr),
    m_SuitNbr(suitNbr)
{
    // Function body deliberately blank.
}

QString Card::toString() const
{
    return QString("%1 of %2")
                  .arg(s_Faces[m_FaceNbr])
                  .arg(s_Suits[m_SuitNbr]);
}

QString Card::getFace() const
{
    return s_Faces[m_FaceNbr];
}

QString Card::getSuit() const
{
    return s_Suits[m_SuitNbr];
}

int Card::getValue() const
{
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
