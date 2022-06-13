//This is client code to test the Film and FilmList ADT's.

#include <QTextStream>
#include "filmList.h"

using namespace std;

int main()
{
    FilmList list1;

    *Educational film1 = new Film(QString("012341"), QString("Blue Planet"),
            QString("Ben Burtt"), 40.0, QDate(1990, 7, 13), QString("Science"), 8);

    list1.addFilm(film1);

    return 0;
}
