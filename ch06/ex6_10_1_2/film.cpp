#include "film.h"

Film::Film(QString id, QString title, QString dir,
            double length, QDate relDate) 
    : m_FilmID(id), m_Title(title), m_Director(dir), 
    m_FilmLength(length), m_ReleaseDate(relDate)
{
    //Function body intentionally empty.
}

Film::Film(QStringList& propList) 
    : m_FilmID(propList.takeFirst()), m_Title(propList.takeFirst()), 
    m_Director(propList.takeFirst())
{
    m_FilmLength = propList.takeFirst().toDouble();
    m_ReleaseDate = QDate::fromString(propList.takeFirst(), Qt::TextDate);
}

QString Film::getFilmID() const
{
    return m_FilmID;
}

QString Film::getTitle() const
{
    return m_Title;
}

Educational::Educational(QString id, QString title, QString dir,
                            double length, QDate relDate, QString subject,
                            int grade) 
    : Film(id, title, dir, length, relDate), 
    m_Subject(subject), m_GradeLevel(grade)
{
    //Function body intentionally empty.
}

Educational::Educational(QStringList& propList) 
    : Film(propList), m_Subject(propList.takeFirst()) 
{
    m_GradeLevel = propList.takeFirst().toInt();
}

QString Educational::toString(bool labeled, QString sepchar) const
{
    if (labeled)
        return QString("Film ID: %1%2 Title: %3%4 Director: %5%6 Length: %7%8
                Release Date: %9%10 Subject: %11%12 Grade Level: %13")
            .arg(m_FilmID).arg(sep).arg(m_Title).arg(sep).arg(m_Director)
            .arg(sep).arg(m_FilmLength).arg(sep).arg(m_ReleaseDate.toString())
            .arg(sep).arg(m_Subject).arg(sep).arg(m_GradeLevel);
    else
        return QString("%1%2%3%4%5%6%7%8%9%10%11%12%13")
            .arg(m_FilmID).arg(sep).arg(m_Title).arg(sep).arg(m_Director)
            .arg(sep).arg(m_FilmLength).arg(sep).arg(m_ReleaseDate.toString())
            .arg(sep).arg(m_Subject).arg(sep).arg(m_GradeLevel);
}

Entertainment::Entertainment(QString id, QString title, QString dir,
                            double length, QDate relDate, FilmTypes type,
                            MPAARatings rating) 
    : Film(id, title, dir, length, relDate), 
    m_Type(type), m_Rating(rating)
{
    //Function body intentionally empty.
}

Entertainment::Entertainment(QStringList& propList) 
    : Film(propList)
{
    m_Type = propList.takeFirst();
    m_Rating = propList.takeFirst();
}

QString Entertainment::toString(bool labeled, QString sepchar) const
{
    if (labeled)
        return QString("Film ID: %1%2 Title: %3%4 Director: %5%6 Length: %7%8
                Release Date: %9%10 Type: %11%12 MPAA Rating: %13")
            .arg(m_FilmID).arg(sep).arg(m_Title).arg(sep).arg(m_Director)
            .arg(sep).arg(m_FilmLength).arg(sep).arg(m_ReleaseDate.toString())
            .arg(sep).arg(m_Type).arg(sep).arg(m_Rating);
    else
        return QString("%1%2%3%4%5%6%7%8%9%10%11%12%13")
            .arg(m_FilmID).arg(sep).arg(m_Title).arg(sep).arg(m_Director)
            .arg(sep).arg(m_FilmLength).arg(sep).arg(m_ReleaseDate.toString())
            .arg(sep).arg(m_Type).arg(sep).arg(m_Rating);
}
