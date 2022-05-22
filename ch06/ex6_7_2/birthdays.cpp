// This is a program to store birthdays and print birthdays
// within a given range using command line arguments.

#include "argumentlist.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDate>
#include <QDebug>

using namespace std;

void addToBirthdays(QFile& data, const ArgumentList& al);
// Precondition: data has been opened and checked for errors.
// Postcondition: names in al added to data.

void printBirthdays(QFile& data, bool numSpecified, const ArgumentList& al);
// Precondition: data has been opened and checked for errors.
// Postcondition: names in data printed to console according
//  to numSpecified condition.

QDate extractDate(const QString& line);
// Function to extract a QDate object from a QString representing
// a name and birth date.
// Postcondition: Returned QString object representing birth date.

int main(int argc, char* argv[])
{
    ArgumentList al(argc, argv);

    QString appname = al.takeFirst();

    bool adding = al.getSwitch("-a");
    bool numSpecified = al.getSwitch("-n");

    // Open data file for writing/reading.
    QFile data("birthdays.dat");

    if (adding) {
        if (data.open(QIODevice::Append))
            addToBirthdays(data, al);
        else
            qDebug() << "Error: file cannot be opened for writing.";
    } else {
        if (data.open(QIODevice::ReadOnly))
            printBirthdays(data, numSpecified, al);
        else
            qDebug() << "Error: file cannot be opened for reading.";
    }

    // Close data.
    data.close();

    return 0;
}

void addToBirthdays(QFile& data, const ArgumentList& al)
{
    QTextStream out(&data);
    QString name;
    QDate date;

    // Add name and date to file in correct format.
    name = QString(al[0]);
    date = QDate::fromString(al[1], Qt::ISODate);
    out << name << '\t' << date.toString(Qt::ISODate) << '\n'; 
}

void printBirthdays(QFile& data, bool numSpecified, const ArgumentList& al)
{
    QTextStream out(stdout), in(&data);
    QString nameSpec;
    QDate date;
    int numDays = 0;

    // Process command line arguments.
    if (numSpecified) {
        bool ok = true;
        numDays = al[0].toInt(&ok, 10);
    } else if (al.size() > 0) {
        nameSpec = QString(al[0]);
    } else numDays = 30;

    // Output appropriate file contents.
    if (nameSpec.size() > 0) {
        while (!in.atEnd()) {
            QString line = in.readLine();
            // Output lines containing nameSpec.
            if (line.contains(nameSpec))
                out << line << '\n';
        }
    } else {
        while (!in.atEnd()) {
            QString line = in.readLine();
            // Extract date from line.
            date = extractDate(line);
            if ((date.dayOfYear() - QDate::currentDate().dayOfYear() < numDays 
                    && date.dayOfYear() - QDate::currentDate().dayOfYear() > 0) 
                || ((date.daysInYear() + date.dayOfYear()) - QDate::currentDate().dayOfYear() 
                < numDays && date.daysInYear() + date.dayOfYear()) - QDate::currentDate().dayOfYear() 
                > 0)
                out << line << '\n';
        }
    }
}

QDate extractDate(const QString& line)
{
    QStringList list = line.split(QLatin1Char(' '));

    return QDate::fromString(list.takeLast(), Qt::ISODate);
}
