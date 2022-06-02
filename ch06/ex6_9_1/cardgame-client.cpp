// This is a driver program to test the ADTs Card, CardHand, & CardDeck.

#include "carddeck.h"
#include <QApplication>
#include <QTextStream>
#include <QInputDialog>
#include <QString>
#include <QMessageBox>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QTextStream cout(stdout);
    CardDeck deck;
    CardHand hand;
    int handSize, playerScore, progScore;
    bool ok;

    cout << "How many cards in a hand? " << flush;
    handSize = QInputDialog::getInt(0, QString("Input Hand Size"),
             QString("How many cards in hand?"), 1, 1, 5, 1, &ok);

    if (ok) {
        QMessageBox::StandardButton sb;
        do {
            hand = deck.deal(handSize);
            cout << "Here is your hand:" << endl;
            cout << hand.toString() << endl;
            playerScore = hand.getValue();
            cout << QString("Your score is: %1 points.")
                            .arg(playerScore) << endl;

            // Now a hand for the dealer:
            hand = deck.deal(handSize);
            progScore = hand.getValue();
            cout << "Here is my hand:" << endl;
            cout << hand.toString() << endl;
            cout << QString("My score is: %1 points.")
                            .arg(progScore) << endl;
            cout << QString("%1 win!!")
                    .arg((playerScore > progScore)?"You":"I") << endl;

            sb = QMessageBox::question(0, QString("QMessageBox::question()"),
                    QString("Another hand?"), QMessageBox::Yes | QMessageBox::No);
        } while (sb == QMessageBox::Yes);

        return EXIT_SUCCESS;
    }
    else
        return EXIT_FAILURE;
}
