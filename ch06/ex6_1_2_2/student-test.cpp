#include <QApplication>
#include <QMessageBox>
#include <QString>
#include "student.h"


QString finish(Student* student) {
    QString result = QString("\n%1%2%3\n %4\n")
        .arg("The following ")
        .arg(student->getClassName())
        .arg(" has applied for graduation.")
        .arg(student->toString());

    switch(student->getYear()) {
    case 1:
    case 2:
    case 3:
        result.append("\nStudent has not completed the required 4 years.\nApplication rejected.\n");
        break;
    case 4:
        result.append("\nStudent has completed the required 4 years.\nApplication accepted.\n");
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        result.append("\nGrad students may graduate at any time.\nApplication accepted.\n");
        break;
    default:
        result.append("\nWe do not have a record of this student\'s year.")
            .append("\nPlease complete profile before processing application.\n");
        break;
    }

    return result;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QMessageBox msgBox;

    Undergrad us("Frodo Baggins", 5562, "Ring Theory", 4, 1220);
    GradStudent gs("Bilbo Baggins", 3029, "History", 6, GradStudent::fellowship);

    QString response = QString("%1\n%2\n%3\n\n%4\n")
        .arg("Here is the data for the two students:")
        .arg(gs.toString())
        .arg(us.toString())
        .arg("Here is what happens when they finish their studies:");

    msgBox.setText(response);
    msgBox.exec();

    response = finish(&us);
    msgBox.setText(response);
    msgBox.exec();

    response = finish(&gs);
    msgBox.setText(response);
    msgBox.exec();

    return 0;
}
