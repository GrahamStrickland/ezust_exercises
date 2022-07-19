#include <QTextStream>
#include <QDebug>
#include "person.h"

static QTextStream cout(stdout);

void showTree(QObject* theparent) {
    cout << "QObject::A Stack Object\n";
    int tabs = 1;
    foreach (QObject* thechild, theparent->findChildren<Person*>()) {
        if (thechild->parent()->objectName() == theparent->objectName()) {
            tabs = 1;
            for (int i = 0; i < tabs; i++)
                cout << '\t';
            cout << "QObject::" << thechild->objectName() << '\n';
            tabs++;
        } else {
            for (int i = 0; i < tabs; i++)
                cout << '\t';
            cout << "QObject::" << thechild->objectName() << '\n';
        }
    }
}

void growBunch() {
    qDebug() << "First we create a bunch of objects." << endl;
    QObject bunch;
    bunch.setObjectName("A Stack Object");  /* A local stack object - not a pointer */
    /* other objects are created on the heap */
    Person* mike = new Person("Mike", &bunch);
    Person* carol = new Person("Carol", &bunch);
    new Person("Greg", mike);               /* We do not need
             to keep pointers to children, because we can
             reach them via object navigation. */
    new Person("Peter", mike);
    new Person("Bobby", mike);
    new Person("Marcia", carol);
    new Person("Jan", carol);
    new Person("Cindy", carol);
    new Person("Alice");                    /* Alice has no parent - memory leak? */
    qDebug() << "\nDisplay the list using showtree(&bunch)"
             << endl;
    showTree(&bunch);
    cout << "\nReady to return from growBunch() -"
         << " Destroy all local stack objects." << endl;
}

int main(int , char**) {
   growBunch();
   cout << "We have now returned from growBunch()."
        <<  "\nWhat happened to Alice?" << endl;
   return 0;
}
