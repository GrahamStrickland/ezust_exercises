#ifndef FILM_H
#define FILM_H

#include <QString>
#include <QStringList>
#include <QDate>

using namespace std;

class Film
{
public:
    virtual QString toString(bool labeled, 
            QString sep) const = 0;
        //Function to return the name of the film 
        //  and production details.
        //Postcondition: Returned QString containing 
        //  film details, with fields separated by sepchar.
      
    virtual QString getFilmID() const = 0;
        //Function to return the ID of the film.
        //Postcondition: Returned m_FilmID;

    virtual QString getTitle() const = 0;
        //Function to return the title of the film.
        //Postcondition: Returned m_Title;

    virtual ~Film() {}
};

class Educational: public Film
{
public:
    Educational(QString id, QString title, QString dir, 
            double length, QDate relDate, QString subject,
            int grade);
        //Constructor with arguments.

    Educational(QStringList& propList);
        //Constructor with list of arguments.

    QString toString(bool labeled, QString sep) const;
        //Function to return the name of the film 
        //  and production details.
        //Postcondition: Returned QString containing 
        //  film details, with fields separated by sepchar.

    QString getFilmID() const;
        //Function to return the ID of the film.
        //Postcondition: Returned m_FilmID;

    QString getTitle() const;
        //Function to return the title of the film.
        //Postcondition: Returned m_Title;

protected:
    QString m_FilmID, m_Title, m_Director;
    double m_FilmLength;
    QDate m_ReleaseDate;
    QString m_Subject;
    int m_GradeLevel;
};

class Entertainment: public Film
{
public:
    enum FilmTypes {NoType = -1, Action, Comedy, SciFi};
    enum MPAARatings {NoRating = -1, G, PG, PG13};

    Entertainment(QString id, QString title, QString dir, 
            double length, QDate relDate, FilmTypes type,
            MPAARatings rating);
        //Constructor with arguments.

    Entertainment(QStringList& propList);
        //Constructor with list of arguments.

    QString toString(bool labeled, QString sep) const;
        //Function to return the name of the film 
        //  and production details.
        //Postcondition: Returned QString containing 
        //  film details, with fields separated by sepchar.

    QString getFilmID() const;
        //Function to return the ID of the film.
        //Postcondition: Returned m_FilmID;

    QString getTitle() const;
        //Function to return the title of the film.
        //Postcondition: Returned m_Title;

private:
    QString m_FilmID, m_Title, m_Director;
    double m_FilmLength;
    QDate m_ReleaseDate;
    FilmTypes m_Type;
    MPAARatings m_Rating;
};

#endif //FILM_H
