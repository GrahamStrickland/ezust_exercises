//This is client code to test the Film and FilmList ADT's.

#include <QTextStream>
#include "filmList.h"

using namespace std;

int main()
{
    QTextStream cout(stdout);
    FilmList list;
    QStringList propList;

    // Test Educational derived class with both constructors.
    Educational *film1 = new Educational(QString("012341"), QString("Blue Planet"),
            QString("Ben Burtt"), 40.0, QDate(1990, 7, 13), QString("Science"), 8);
    propList << "057271" << "Ways of Seeing" << "John Berger" << "30.0"
             << "Wed Jan 5 1972" << "Art" << "10";
    Educational *film2 = new Educational(propList);

    // Test Entertainment derived class with both constructors.
    Entertainment *film3 = new Entertainment(QString("056182"), QString("Old School"),
            QString("Todd Phillips"), 90.0, QDate(2003, 2, 21), Entertainment::Action,
            Entertainment::PG13);
    propList.clear();
    propList << "051234" << "12 Monkeys" << "Terry Gilliam" << "129.0" << "Fri Dec 29 1995"
             << "SciFi" << "PG-13";
    Entertainment *film4 = new Entertainment(propList);

    // Add films to list.
    list.addFilm(film1);
    list.addFilm(film2);
    list.addFilm(film3);
    list.addFilm(film4);

    // Output film list.
    cout << "Film list contains the following movies: " << endl << endl
         << list.toString() << endl;

    // Test deleting and adding element already in list.
    list.removeFilm(QString("012341"));
    Entertainment *film5 = new Entertainment(propList);
    list.addFilm(film5);
    
    return 0;
}
