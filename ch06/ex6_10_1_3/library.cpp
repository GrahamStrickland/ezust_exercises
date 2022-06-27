#include "library.h"

Library::~Library() {
    qDeleteAll(*this);
    clear();
}

void Library::addRefItem(RefItem*& refitem) {
    QString isbn(refitem->getISBN());
    RefItem* oldItem(findRefItem(isbn));
    if(oldItem==0)
        append(refitem);
    else {
        qDebug() << isbn << " already in list:\n"
                 << oldItem->toString()
                 << "\nIncreasing number of copies "
                 << "and deleting new pointer.";
        int newNum(oldItem->getNumberOfCopies() + refitem->getNumberOfCopies());
        oldItem->setNumberOfCopies(newNum);
        delete refitem;
        refitem = 0;
    }
}

int Library::removeRefItem(QString isbn) {
    RefItem* ref(findRefItem(isbn));
    int numCopies(-1);
    if(ref) {
        numCopies = ref->getNumberOfCopies() - 1;
        if(numCopies==-0) {
            removeAll(ref);
            delete ref;
        }
        else
            ref->setNumberOfCopies(numCopies);
    }
    return numCopies;
}

bool Library::isInList(QString isbn) {
    return findRefItem(isbn);
}

QString Library::toString(QString sep) const {
    QStringList reflst;
    for(int i = 0; i < size(); ++i)
        reflst << at(i)->toString();
    return reflst.join(sep);
}

QString Library::getItemString(QString isbn) {
    RefItem* ref(findRefItem(isbn));
    if (ref)
        return ref->toString();
    else
        return QString();
}

Library::Library(const Library&) : QList<RefItem*> {}

Library& Library::operator=(const Library&) {
    return *this;
}

RefItem* Library::findRefItem(QString isbn) {
    for(int i = 0; i < size(); ++i) {
        if(at(i)->getISBN().trimmed() == isbn.trimmed())
            return at(i);
    }
    return 0;
}

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
    m_ISBN(plst.takeFirst()), m_Title(plst.takeFirst),
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

RefCategory ReferenceBook::getCategory() const {
    return m_Category;
}

QString ReferenceBook::categoryString() const {
    switch(m_Category) {
        case Art: return "Art";
        case Architectur: return "Architecture";
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

TextCategory TextBook::getCategory() const {
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

QStringList TextBook::getTextCategories()
{
    QStringList list;
    
    list << "Biology" << "Chemistry" << "Law" << "Mathematics" << "Philosophy"
         << "Psychology" << "Physics";
    
    return list;
}
