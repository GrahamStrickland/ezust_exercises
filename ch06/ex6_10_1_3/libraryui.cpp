#include <QTextStream>
#include <QFile>
#include <QIODevice>
#include <QDebug>
#include <QDate>

#include "libraryui.h"

QTextStream cout(stdout);
QTextStream cin(stdin);
const QStringList TYPES = {QStringList() << "BOOK" << "REFERENCEBOOK"
    << "TEXTBOOK" << "DVD" << "FILM" << "DATADVD"};

LibraryUI::LibraryUI(Library* lib) : m_Lib(lib)
{}

void LibraryUI::add(QStringList objdata) {
    cout << objdata.join("[::]") << endl;
    QString type = objdata.first();
    RefItem* ref;
    switch (static_cast<Types>(TYPES.indexOf(type))) {
    case BOOK:
        ref = new Book(objdata);
        m_Lib->addRefItem(ref);
        break;
    case REFERENCEBOOK:
        ref = new ReferenceBook(objdata);
        m_Lib->addRefItem(ref);
        break;
    case TEXTBOOK:
        ref = new TextBook(objdata);
        m_Lib->addRefItem(ref);
        break;
    case DVD:
        ref = new Dvd(objdata);
        m_Lib->addRefItem(ref);
        break;
    case FILM:
        ref = new Film(objdata);
        m_Lib->addRefItem(ref);
        break;
    case DATADVD:
        ref = new DataBase(objdata);
        m_Lib->addRefItem(ref);
        break;
    default: qDebug() << "Bad type in add() function";
    }
}

void LibraryUI::read() {
    const QString sep("[::]");
    const int BADLIMIT(5);  //max number of bad lines
    QString line, type;
    QStringList objdata;
    QFile inf("libfile");
    inf.open(QIODevice::ReadOnly);
    QTextStream instr(&inf);
    int badlines(0);

    while (not instr.atEnd()) {
        if (badlines >= BADLIMIT) {
            qDebug() << "Too many bad lines! Aborting.";
            return;
        }
        line = instr.readLine();
        objdata = line.split(sep);
        if (objdata.isEmpty()) {
            qDebug() << "Empty line in file!";
            ++badlines;
        }
        else if (not TYPES.contains(objdata.first())) {
            qDebug() << "Bad type in line: " << objdata.join(";;;");
            ++badlines;
        }
        else
            add(objdata);
    }
}

void LibraryUI::enterData() {
    QString typestr;
    while (1) {
        cout << "Library item type: " << flush;
        typestr = cin.readLine();
        if (not TYPES.contains(typestr)) {
            cout << "Please enter one of the following types:\n"
                 << TYPES.join(", ") << endl;
            continue;
        }
        break;
    }
    QStringList objdata;
    switch (TYPES.indexOf(typestr)) {
    case BOOK: objdata = promptBook();
        break;
    case REFERENCEBOOK: objdata = promptReferenceBook();
        break;
    case TEXTBOOK: objdata = promptTextBook();
       break;
    case DVD: objdata = promptDvd();
       break;
    case FILM: objdata = promptFilm();
       break;
    case DATADVD: objdata = promptDataBase();
       break;
    default:
        qDebug() << "Bad type in enterData()";
    }
    objdata.prepend(typestr);
    add(objdata);
}

QString LibraryUI::find() const {
    QString isbnstr;
    while (1) {
        cout << "Please enter ISBN of library item: " << flush;
        isbnstr = cin.readLine();
        if (not m_Lib->isInList(isbnstr)) {
            cout << "Error: invalid ISBN number, please enter "
                 << "another ISBN: ";
            continue;
        }
        break;
    }
    return m_Lib->findRefItem(isbnstr)->toString();
}

void LibraryUI::remove() {
    QString isbnstr;
    while (1) {
        cout << "Please enter ISBN of reference item: " << flush;
        isbnstr = cin.readLine();
        if (not m_Lib->isInList(isbnstr)) {
            cout << "Error: invalid ISBN number, please enter "
                 << "another ISBN: ";
            continue;
        }
        break;
    }
    m_Lib->removeOne(m_Lib->findRefItem(isbnstr));
}

void LibraryUI::save() {
    QFile outf("libfile");
    outf.open(QIODevice::WriteOnly);
    QTextStream outstr(&outf);
    outstr << m_Lib->toString(QString("\n"));
    outf.close();
}

void LibraryUI::list() {
    cout << m_Lib->toString(QString("\n"));
}

QStringList LibraryUI::promptRefItem() {
    const int MAXCOPIES(10);
    const int ISBNLEN(13);
    int copies;
    QString str;
    QStringList retval;
    while (1) {
        cout << "ISBN (" << ISBNLEN << " digits): " << flush;
        str = cin.readLine();
        if (str.length() == ISBNLEN) {
            retval << str;
            break;
        }
    }
    cout << "Title: " << flush;
    retval << cin.readLine();
    while (1) {
        cout << "Number of copies: " << flush;
        copies = cin.readLine().toInt();
        if (copies > 0 and copies <= MAXCOPIES) {
            str.setNum(copies);
            break;
        }
    }
    retval << str;
    return retval;
}

QStringList LibraryUI::promptBook() {
    static const int MINYEAR(1900), MAXYEAR(QDate::currentDate().year());
    int year;
    QStringList retval(promptRefItem());
    QString str;
    cout << "Author: " << flush;
    retval << cin.readLine();
    cout << "Publisher: " << flush;
    retval << cin.readLine();
    while (1) {
        cout << "Copyright year: " << flush;
        year = cin.readLine().toInt();
        if (year >= MINYEAR and year <= MAXYEAR) {
            str.setNum(year);
            break;
        }
    }
    retval << str;
    return retval;
}

QStringList LibraryUI::promptReferenceBook() {
    int idx(0);
    bool ok;
    QString str;
    QStringList retval(promptBook());
    QStringList cats(ReferenceBook::getRefCategories());
    while (1) {
        cout << "Enter the index of the correct Reference Category: ";
        for (int i = 0; i < cats.size(); ++i) 
            cout << "\n\t(" << i << ") " << cats.at(i);
        cout << "\n\t(-1)None of these\t:::" << flush;
        idx = cin.readLine().toInt(&ok);
        if (ok) {
            retval << str.setNum(idx);
            break;
        }
    }
    return retval;
}

QStringList LibraryUI::promptTextBook() {
    int idx(0);
    bool ok;
    QString str;
    QStringList retval(promptBook());
    QStringList cats(TextBook::getTextCategories());
    while (1) {
        cout << "Enter the index of the correct Textbook Category: ";
        for (int i = 0; i < cats.size(); ++i) 
            cout << "\n\t(" << i << ") " << cats.at(i);
        cout << "\n\t(-1)None of these\t:::" << flush;
        idx = cin.readLine().toInt(&ok);
        if (ok) {
            retval << str.setNum(idx);
            break;
        }
    }
    return retval;
}

QStringList LibraryUI::promptDvd() {
    static const int MINYEAR(1900), MAXYEAR(QDate::currentDate().year());
    int year;
    QStringList retval(promptRefItem());
    QString str;
    cout << "Creator: " << flush;
    retval << cin.readLine();
    cout << "Publisher: " << flush;
    retval << cin.readLine();
    while (1) {
        cout << "Copyright year: " << flush;
        year = cin.readLine().toInt();
        if (year >= MINYEAR and year <= MAXYEAR) {
            str.setNum(year);
            break;
        }
    }
    retval << str;
    return retval;
}

QStringList LibraryUI::promptFilm() {
    int idx(0);
    bool ok;
    QString str;
    QStringList retval(promptDvd());
    QStringList cats(Film::getFilmCategories());
    while (1) {
        cout << "Enter the index of the correct Film Category: ";
        for (int i = 0; i < cats.size(); ++i) 
            cout << "\n\t(" << i << ") " << cats.at(i);
        cout << "\n\t(-1)None of these\t:::" << flush;
        idx = cin.readLine().toInt(&ok);
        if (ok) {
            retval << str.setNum(idx);
            break;
        }
    }
    return retval;
}

QStringList LibraryUI::promptDataBase() {
    int idx(0);
    bool ok;
    QString str;
    QStringList retval(promptDvd());
    QStringList cats(DataBase::getDBCategories());
    while (1) {
        cout << "Enter the index of the correct DataBase Category: ";
        for (int i = 0; i < cats.size(); ++i) 
            cout << "\n\t(" << i << ") " << cats.at(i);
        cout << "\n\t(-1)None of these\t:::" << flush;
        idx = cin.readLine().toInt(&ok);
        if (ok) {
            retval << str.setNum(idx);
            break;
        }
    }
    return retval;
}

LibraryUI::Choices LibraryUI::nextTask() {
    int choice;
    QString response;
    do {
        cout << READ << ". Read data from a file.\n"
             << ADD << ". Add items to the Library.\n"
             << FIND << ". Find and display an item.\n"
             << REMOVE << ". Remove an item from the Library.\n"
             << SAVE << ". Save the Library list to a file.\n"
             << LIST << ". Brief listing of Library items.\n"
             << QUIT << ". Exit from this program.\n"
             << "Your choice: " << flush;
        response = cin.readLine();
        choice = response.toInt();
    } while (choice < READ or choice > QUIT);
    return static_cast<Choices>(choice);
}

void LibraryUI::prepareToQuit(bool saved) {
    QString ans;

    if (!saved) {
        cout << "Library has not been saved. Would you like to save? ";
        ans = cin.readLine();
    }

    if (ans == QString("Yes") || ans == QString("yes") || ans == QString("YES")
            || ans == QString("Y") || ans == QString("y"))
        save();
}
