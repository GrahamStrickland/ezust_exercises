#include "library.h"

RefItem::RefItem(QStringList& plst) : m_ItemType(plst.takeFirst()),
    m_ISBN(plst.takeFirst()), m_Title(plst.takeFirst),
    m_NumberOfCopies(plst.takeFirst().toInt())
{}

QString RefItem::toString(QString sep) const {
    return
        QString("%1%2%3%4%5%6%7").arg(m_ItemType).arg(sep).arg(m_ISBN).arg(sep)
                                .arg(m_Title).arg(sep).arg(m_NumberOfCopies);
}

Book::Book(QStringList& plst) : RefItem(plst), m_Author(plst.takeFirst()),
    m_Publisher(plst.takeFirst()), m_CopyrightYear(plst.takeFirst().toInt())
{}

QString Book::toString(QString sep) const {
    return QString("%1%2%3%4%5%6%7").arg(RefItem::toString(sep)).arg(sep)
                .arg(m_Author).arg(sep).arg(m_Publisher).arg(sep)
                .arg(m_CopyrightYear);
}

ReferenceBook::ReferenceBook(QStringList& plst) : Book(plst),
    m_Category(static_cast<RefCategory>(plst.takeFirst().toInt()))
{}

QString ReferenceBook::toString(QString sep) const {
    return QString("%1%2%3").arg(Book::toString(sep)).arg(sep)
                            .arg(categoryString());
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

Library::~Library() {
    qDeleteAll(*this);
    clear();
}

Library::Library(const Library&) : QList<RefItem*> {}

Library& Library::operator=(const Library&) {
    return *this;
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

RefItem* Library::findRefItem(QString isbn) {
    for(int i = 0; i < size(); ++i) {
        if(at(i)->getISBN().trimmed() == isbn.trimmed())
            return at(i);
    }
    return 0;
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
