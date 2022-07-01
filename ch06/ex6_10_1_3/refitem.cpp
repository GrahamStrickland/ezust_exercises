#include "refitem.h"

RefItem::~RefItem()
{}

QString RefItem::getItemType() const {
    return m_ItemType;
}

QString RefItem::getISBN() const {
    return m_ISBN;
}

QString RefItem::getTitle() const {
    return m_Title;
}

int RefItem::getNumberOfCopies() const {
    return m_NumberOfCopies;
}

QString RefItem::toString(QString sep) const {
    return
        QString("%1%2%3%4%5%6%7").arg(m_ItemType).arg(sep).arg(m_ISBN).arg(sep)
                                .arg(m_Title).arg(sep).arg(m_NumberOfCopies);
}

void RefItem::setNumberOfCopies(int newVal) {
    m_NumberOfCopies = newVal;
}

RefItem::RefItem(QString type, QString isbn, QString title, int numCopies)
    : m_ItemType(type), m_ISBN(isbn), m_Title(title), m_NumberOfCopies(numCopies)
{}

RefItem::RefItem(QStringList& plst) : m_ItemType(plst.takeFirst()),
    m_ISBN(plst.takeFirst()), m_Title(plst.takeFirst()),
    m_NumberOfCopies(plst.takeFirst().toInt())
{}

Book::Book(QString type, QString isbn, QString title, QString author, QString pub,
        int year, int numCopies) : RefItem(type, isbn, title, numCopies), 
    m_Author(author), m_Publisher(pub), 
    m_CopyrightYear(year)
{}

Book::Book(QStringList& plst) : RefItem(plst), m_Author(plst.takeFirst()),
    m_Publisher(plst.takeFirst()), m_CopyrightYear(plst.takeFirst().toInt())
{}

QString Book::toString(QString sep) const {
    return QString("%1%2%3%4%5%6%7").arg(RefItem::toString(sep)).arg(sep)
                .arg(m_Author).arg(sep).arg(m_Publisher).arg(sep)
                .arg(m_CopyrightYear);
}

QString Book::getAuthor() const {
    return m_Author;
}

QString Book::getPublisher() const {
    return m_Publisher;
}

int Book::getCopyRightYear() const {
    return m_CopyrightYear;
}

ReferenceBook::ReferenceBook(QString type, QString isbn, QString title,
        QString author, QString pub, int year, RefCategory refcat, int numCopies)
    : Book(type, isbn, title, author, pub, year, numCopies), m_Category(refcat)
{}

ReferenceBook::ReferenceBook(QStringList& plst) : Book(plst),
    m_Category(static_cast<RefCategory>(plst.takeFirst().toInt()))
{}

QString ReferenceBook::toString(QString sep) const {
    return QString("%1%2%3").arg(Book::toString(sep)).arg(sep)
                            .arg(categoryString());
}

ReferenceBook::RefCategory ReferenceBook::getCategory() const {
    return m_Category;
}

QString ReferenceBook::categoryString() const {
    switch(m_Category) {
    case Art: return "Art";
    case Architecture: return "Architecture";
    case ComputerScience: return "ComputerScience";
    case Literature: return "Literature";
    case Math: return "Math";
    case Music: return "Music";
    case Science: return "Science";
    default: return "None";
    }
}

QStringList ReferenceBook::getRefCategories()
{
    QStringList list;
    
    list << "Art" << "Architecture" << "ComputerScience" << "Literature" << "Math"
         << "Music" << "Science";
    
    return list;
}

TextBook::TextBook(QString type, QString isbn, QString title,
        QString author, QString pub, int year, TextCategory textcat, int numCopies)
    : Book(type, isbn, title, author, pub, year, numCopies), m_Category(textcat)
{}

TextBook::TextBook(QStringList& plst) : Book(plst),
    m_Category(static_cast<TextCategory>(plst.takeFirst().toInt()))
{}

QString TextBook::toString(QString sep) const {
    return QString("%1%2%3").arg(Book::toString(sep)).arg(sep)
                            .arg(categoryString());
}

TextBook::TextCategory TextBook::getCategory() const {
    return m_Category;
}

QString TextBook::categoryString() const {
    switch(m_Category) {
    case Biology: return "Biology";
    case Chemistry: return "Chemistry";
    case Law: return "Law";
    case Mathematics: return "Mathematics";
    case Philosophy: return "Philosophy";
    case Psychology: return "Psychology";
    case Physics: return "Physics";
    default: return "None";
    }
}

QStringList TextBook::getTextCategories() {
    QStringList list;
    
    list << "Biology" << "Chemistry" << "Law" << "Mathematics" << "Philosophy"
         << "Psychology" << "Physics";
    
    return list;
}

Dvd::Dvd(QString type, QString isbn, QString title, QString creator, 
        QString pub, int year, int numCopies) : RefItem(type, isbn, title, numCopies),
    m_Creator(creator), m_Publisher(pub), m_CopyrightYear(year)
{}

Dvd::Dvd(QStringList& proplist) : RefItem(proplist), m_Creator(proplist.takeFirst()),
    m_Publisher(proplist.takeFirst()), m_CopyrightYear(proplist.takeFirst().toInt())
{}

QString Dvd::toString(QString sep) const {
    return QString("%1%2%3%4%5%6%7").arg(RefItem::toString(sep)).arg(sep)
                .arg(m_Creator).arg(sep).arg(m_Publisher).arg(sep)
                .arg(m_CopyrightYear);
}

int Dvd::getCopyrightYear() const {
    return m_CopyrightYear;
}

QString Dvd::getCreator() const {
    return m_Creator;
}

QString Dvd::getPublisher() const {
    return m_Publisher;
}

Film::Film(QString type, QString isbn, QString title, QString creator, QString pub,
        int year, FilmCategory filmcat, int numCopies) : 
    Dvd(type, isbn, title, creator, pub, year, numCopies), m_Category(filmcat)
{}

Film::Film(QStringList& proplist) : Dvd(proplist),
    m_Category(static_cast<FilmCategory>(proplist.takeFirst().toInt()))
{}

QString Film::toString(QString sep) const {
    return QString("%1%2%3").arg(Dvd::toString(sep)).arg(sep)
                            .arg(categoryString());
}

Film::FilmCategory Film::getCategory() const {
    return m_Category;
}

QString Film::categoryString() const {
    switch(m_Category) {
    case Action: return "Action";
    case Comedy: return "Comedy";
    case Romance: return "Romance";
    case Thriller: return "Thriller";
    default: return "None";
    }
}

QStringList Film::getFilmCategories() {
    QStringList list;

    list << "Action" << "Comedy" << "Romance" << "Thriller";

    return list;
}

DataBase::DataBase(QString type, QString isbn, QString title, QString creator, QString pub,
        int year, DBCategory dbcat, int numCopies) :
    Dvd(type, isbn, title, creator, pub, year, numCopies), m_Category(dbcat)
{}

DataBase::DataBase(QStringList& proplist) : Dvd(proplist),
    m_Category(static_cast<DBCategory>(proplist.takeFirst().toInt()))
{}

QString DataBase::toString(QString sep) const {
    return QString("%1%2%3").arg(Dvd::toString(sep)).arg(sep)
                            .arg(categoryString());
}

DataBase::DBCategory DataBase::getCategory() const {
    return m_Category;
}

QString DataBase::categoryString() const {
    switch(m_Category) {
    case RefBook: return "Reference Book";
    case TextBook: return "Textbook";
    case Film: return "Film";
    default: return "None";
    }
}

QStringList DataBase::getDBCategories() {
    QStringList list;

    list << "Reference Book" << "Textbook" << "Film";

    return list;
}
