#ifndef LIBRARY_UI_H
#define LIBRARY_UI_H

#include "library.h"

using namespace std;

clas LibraryUI
{
public:
    LibraryUI(Library* lib);
        //Constructor

    void add(QStringList objdata);
        //Function to add a RefItem to the Library object.
        //Precondition: objdata contains QStrings to initialize a
        //  RefItem object.
        //Postcondition: RefItem corresponding to objdata added to
        //  m_Lib.

    void save();
        //Function to save the Library object.
        //Postcondition: m_Lib saved to disc stored in file
        //  "libfile".
        
    void read();
        //Function to read in a Library object.
        //Postcondition: m_Lib assigned items stored in libfile.

    QStringList promptRefItem();
        //Function to prompt the user to enter the details of a
        //  RefItem to add to the Library object.
        //Postcondition: RefItem created and returned as a
        //  QStringList.

    QStringList promptBook();
        //Function to prompt the user to enter the details of a
        //  Book to add to the Library object.
        //Postcondition: Book created and returned as a
        //  QStringList.

    QStringList promptReferenceBook();
        //Function to prompt the user to enter the details of a
        //  ReferenceBook to add to the Library object.
        //Postcondition: ReferenceBook created and returned
        //  as a QStringList.

    void enterData();
        //Function to prompt the user to enter the details
        //  of a RefItem stored in a QStringList.
        //Postcondition: RefItem added to m_Lib.
        
private:
    Library* m_Lib;
};
#endif //LIBRARY_UI_H
