#include "film.h"

Educational::Educational(QString id, QString title, QString dir,
                            double length, QDate relDate, QString subject,
                            int grade) 
    : m_FilmID(id), m_Title(title), m_Director(dir), 
    m_FilmLength(length), m_ReleaseDate(relDate),
    m_Subject(subject), m_GradeLevel(grade)
{
    //Function body intentionally empty.
}

Educational::Educational(QStringList& propList) 
    : m_FilmID(propList.takeFirst()), m_Title(propList.takeFirst()), 
    m_Director(propList.takeFirst()) 
{
    m_FilmLength = propList.takeFirst().toDouble();
    m_ReleaseDate = QDate::fromString(propList.takeFirst(), Qt::TextDate);
    m_Subject = propList.takeFirst();
    m_GradeLevel = propList.takeFirst().toInt();
}

QString Educational::toString(bool labeled, QString sep) const
{
    if (labeled)
        return QString("Film ID: %1%2 Title: %3%4 Director: %5%6 Length: %7%8Release Date: %9%10 Subject: %11%12 Grade Level: %13")
            .arg(m_FilmID).arg(sep).arg(m_Title).arg(sep).arg(m_Director)
            .arg(sep).arg(m_FilmLength).arg(sep).arg(m_ReleaseDate.toString())
            .arg(sep).arg(m_Subject).arg(sep).arg(m_GradeLevel);
    else
        return QString("%1%2%3%4%5%6%7%8%9%10%11%12%13")
            .arg(m_FilmID).arg(sep).arg(m_Title).arg(sep).arg(m_Director)
            .arg(sep).arg(m_FilmLength).arg(sep).arg(m_ReleaseDate.toString())
            .arg(sep).arg(m_Subject).arg(sep).arg(m_GradeLevel);
}

QString Educational::getFilmID() const
{
    return m_FilmID;
}

QString Educational::getTitle() const
{
    return m_Title;
}

Entertainment::Entertainment(QString id, QString title, QString dir,
                            double length, QDate relDate, FilmTypes type,
                            MPAARatings rating) 
    : m_FilmID(id), m_Title(title), m_Director(dir), 
    m_FilmLength(length), m_ReleaseDate(relDate),
    m_Type(type), m_Rating(rating)
{
    //Function body intentionally empty.
}

Entertainment::Entertainment(QStringList& propList) 
    : m_FilmID(propList.takeFirst()), m_Title(propList.takeFirst()), 
    m_Director(propList.takeFirst()) 
{
    m_FilmLength = propList.takeFirst().toDouble();
    m_ReleaseDate = QDate::fromString(propList.takeFirst(), Qt::TextDate);
    QString type = propList.takeFirst(), rating = propList.takeFirst();

    if (type.compare("Action", Qt::CaseInsensitive))
        m_Type = Action;
    else if (type.compare("Comedy", Qt::CaseInsensitive))
        m_Type = Comedy;
    else if (type.compare("SciFi", Qt::CaseInsensitive))
        m_Type = SciFi;
    else
        m_Type = NoType;

    if (rating.compare("G", Qt::CaseInsensitive))
        m_Rating = G;
    else if (rating.compare("PG", Qt::CaseInsensitive))
        m_Rating = PG;
    else if (rating.compare("PG-13", Qt::CaseInsensitive))
        m_Rating = PG13;
    else
        m_Rating = NoRating;
}

QString Entertainment::toString(bool labeled, QString sep) const
{
    if (labeled)
        return QString("Film ID: %1%2 Title: %3%4 Director: %5%6 Length: %7%8Release Date: %9%10 Type: %11%12 MPAA Rating: %13")
            .arg(m_FilmID).arg(sep).arg(m_Title).arg(sep).arg(m_Director)
            .arg(sep).arg(m_FilmLength).arg(sep).arg(m_ReleaseDate.toString())
            .arg(sep).arg(m_Type).arg(sep).arg(m_Rating);
    else
        return QString("%1%2%3%4%5%6%7%8%9%10%11%12%13")
            .arg(m_FilmID).arg(sep).arg(m_Title).arg(sep).arg(m_Director)
            .arg(sep).arg(m_FilmLength).arg(sep).arg(m_ReleaseDate.toString())
            .arg(sep).arg(m_Type).arg(sep).arg(m_Rating);
}

QString Entertainment::getFilmID() const
{
    return m_FilmID;
}

QString Entertainment::getTitle() const
{
    return m_Title;
}

