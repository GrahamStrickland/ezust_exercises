#ifndef FILM_H
#define FILM_H

#include <QString>
#include <QStringList>
#include <QDate>

using namespace std;

class Film
{
public:
    Film(QString id, QString title, QString dir, 
            double length, QDate relDate);
        //Constructor with arguments.

    Film(QStringList& propList);
        //Constructor with list of arguments.

    virtual QString toString(bool labeled, 
            QString sepchar) const = 0;
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

    QString toString(bool labeled, QString sepchar) const;
        //Function to return the name of the film 
        //  and production details.
        //Postcondition: Returned QString containing 
        //  film details, with fields separated by sepchar.

private:
    QString m_Subject;
    int m_GradeLevel;
};

class Entertainment: public Film
{
public:
    enum FilmTypes {Action, Comedy, SciFi};
    enum MPAARatings {G, PG, PG13};

    Entertainment(QString id, QString title, QString dir, 
            double length, QDate relDate, FilmTypes type,
            MPAARatings rating);
        //Constructor with arguments.

    Entertainment(QStringList& propList);
        //Constructor with list of arguments.

    QString toString(bool labeled, QString sepchar) const;
        //Function to return the name of the film 
        //  and production details.
        //Postcondition: Returned QString containing 
        //  film details, with fields separated by sepchar.

private:
    FilmTypes m_Type;
    MPAARatings m_Rating;
};

#endif //FILM_H
