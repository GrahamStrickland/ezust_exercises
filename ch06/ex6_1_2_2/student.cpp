#include <QTextStream>
#include "student.h"

Student::Student(QString nm, long id, QString major, int year)
        : m_Name(nm), m_Major(major), m_StudentId(id), m_Year(year) {}

QString Student::getClassName() const {
    return "Student";
}

QString Student::toString() const {
    QString retval;
    QTextStream os(&retval);
    os << "[" << getClassName() << "]"
       << " name: " << m_Name
       << "; Id: " << m_StudentId
       << "; Year: " << yearStr()
       << "; Major: " << m_Major;
    return retval;
}

int Student::getYear() const {
    return m_Year;
}

QString Student::yearStr() const {
    switch(m_Year) {
    case 1:
        return "fresh";
    case 2:
        return "soph";
    case 3:
        return "junior";
    case 4:
        return "senior";
    case 5:
        return "graduate student";
    case 6:
        return "gradual student";
    case 7:
        return "oldtimer";
    case 8:
        return "relic";
    }
    return "unknown";
}

Undergrad::Undergrad(QString name, long id, QString major,
                        int year, int sat)
        : Student(name, id, major, year), m_SAT(sat)
{}

QString Undergrad::getClassName() const {
    return "Undergrad";
}

QString Undergrad::toString() const {
    QString result;
    QTextStream os(&result);
    os << Student::toString()
       << "\n [SAT: "
       << m_SAT
       << " ]\n";
    return result;
}

GradStudent::GradStudent(QString nm, long id, QString major, int yr,
                            Support support) : Student(nm, id, major, yr),
                        m_Support(support) {}

QString GradStudent::toString() const
{
    return QString("%1%2%3 ]\n")
        .arg(Student::toString())
        .arg("\n [Support: ")
        .arg(supportStr(m_Support));
}

QString GradStudent::supportStr(Support sup) {
    switch(sup) {
    case ta:
        return "ta";
    case ra:
        return "ra";
    case fellowship:
        return "fellowship";
    case other:
        return "other";
    }
    return "unknown";
}

QString GradStudent::getClassName() const {
    return "GradStudent";
}
