#include <QDebug>
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

Library::Library(const Library&) : QList<RefItem*>() {}

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
