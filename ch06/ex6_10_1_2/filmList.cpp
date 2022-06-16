#include <QStringList>
#include <QDebug>
#include "filmList.h"

using namespace std;

QString FilmList::toString() const
{
    QStringList list;

    for (int i = 0; i < size(); ++i)
        list << at(i)->toString(true, QString("\n"));

    return list.join('\n');
}

Film* FilmList::findFilm(QString id) const
{
    for (int i = 0; i < size(); ++i) {
        if (at(i)->getFilmID().trimmed() == id.trimmed())
            return at(i);
    }
    
    return 0;
}

QString FilmList::getID(QString title) const
{
    for (int i = 0; i < size(); ++i) {
        if (at(i)->getTitle().trimmed() == title.trimmed())
            return at(i)->getFilmID();
    }
    
    return QString("");
}

void FilmList::addFilm(Film*& film)
{
    QString id(film->getFilmID());

    Film* oldFilm(findFilm(id));

    if (oldFilm == 0)
        append(film);
    else {
        qDebug() << id << "Already in film list:\n"
                 << oldFilm->toString(true, QString("\n"))
                 << "\nDeleting new pointer.";
        delete film;
        film = 0;
    }
}

void FilmList::removeFilm(QString filmID)
{
    Film* film(findFilm(filmID));
    if (film) {
        removeAll(film);
        delete film;
    }
}

FilmList::FilmList()
{

}

FilmList::~FilmList()
{
    qDeleteAll(*this);
    clear();
}
