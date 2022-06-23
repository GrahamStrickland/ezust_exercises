#ifndef LIBRARY_UI_H
#define LIBRARY_UI_H

#include "library.h"

using namespace std;

clas LibraryUI
{
public:
    LibraryUI(Library* lib);
    void add(QStringList objdata);
    void read();
    void enterData();
    QString find(QString title) const;
    void remove(QString title);
    void save();
    void list();
    QStringList promptRefItem();
    QStringList promptBook();
    QStringList promptReferenceBook();
    QStringList promptTextBook();
    QStringList promptDvd();
    QStringList promptFilm();
    QStringList promptDataBase();
    Choices nextTask();
    void prepareToQuit(bool saved);
private:
    Library* m_Lib;
};
#endif //LIBRARY_UI_H
