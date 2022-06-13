#ifndef FILM_LIST_H
#define FILM_LIST_H

#include <QList>
#include "film.h"

class FilmList: public QList<Film*>
{
public:
    QString toString() const;
        //Function to return the details of each
        //  film in the film list.
        //Postcondition: Returned QString containing
        //  details of each film in the film list.
        
    Film* findFilm(QString id) const;
        //Function to return a pointer to the film
        //  with given ID number.
        //Postcondition: Returned pointer to film
        //  object if contained in list; otherwise
        //  error thrown.

    QString getID(QString title) const;
        //Function to return the ID of the film
        //  matching the given title.
        //Postcondition: Returned QString representing
        //  ID of film pointer if contained in list;
        //  otherwise returned empty string.

    void addFilm(Film*& film);
        //Function to add a film to the film list.
        //Postcondition: pointer added to list.

    void removeFilm(QString filmID);
        //Function to remove the film with the give
        //  ID from the film list.
        //Postcondition: pointer removed from list
        //  if list contains film ID; otherwise
        //  error message printed to console.
    
    FilmList();
        //Default constructor.

    ~FilmList();
        //Destructor.
};
#endif //FILM_LIST_H
