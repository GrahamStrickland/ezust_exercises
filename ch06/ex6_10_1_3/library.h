#ifndef LIBRARY_H
#define LIBRARY_H

#include <QString>
#include <QList>
#include <QStringList>

class RefItem {
public:
    virtual ~refItem();
    QString getItemType() const;
    QString getISBN() const;
    QString getTitle() const;
    int getNumberOfCopies() const;
    virtual QString toString(QString sep="[::]") const;
    void setNumberOfCopies(int newVal);
protected:
    RefItem(QString type, QString isbn, QString title, int numCopies=1);
    RefItem(QStringList& proplist);
private:
    QString m_ItemType, m_ISBN, m_Title;
    int m_NumberOfCopies;
};

class Book : public RefItem {
public:
    Book(QString type, QString isbn, QString title, QString author,
            QString pub, int year, int numCopies=1);
    Book(QStringList& proplist);
    virtual QString toString(QString sep="[::]") const;
    QString getAuthor() const;
    QString getPublisher() const;
    int getCopyRightYear() const;
private:
    QString m_Author, m_Publisher;
    int m_CopyrightYear;
};

class ReferenceBook : public Book {
public:
    enum RefCategory {NONE = -1, Art, Architecture, ComputerScience, Literature,
                        Math, Music, Science};
    ReferenceBook(QString type, QString isbn, QString title, QString author,
            QString pub, int year, RefCategory refcat, int numCopies=1);
    ReferenceBook(QString& proplist);
    QString toString(QString sep="[::]") const;
    RefCategory getCategory() const;
    QString categoryString() const; //returns string version of m_Category
    static QStringList getRefCategories();  //returns a list of categories
private:
    RefCategory m_Category;
};

class Library : public QList<RefItem*> {
public:
    Library() {}
    ~Library();
    void addRefItem(RRefItem*& refItem);
    int removeRefItem(QString isbn);
    QString toString(QString isbn);
private:
    Library(const Library&);
    Library& operator=(const Library&);
    RefItem* findRefItem(QString isbn);
};

#endif //LIBRARY_H
