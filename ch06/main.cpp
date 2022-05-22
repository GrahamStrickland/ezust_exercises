#include <iostream>
#include "Base.h"

using namespace std;

int main(int argc, char** argv) {
    Base b;
    Derived d;

    cout << "Objects Created" << endl;
    b.b();
    cout << "Calling derived methods" << endl;
    d.a();
    d.b();
    d.c();
    cout << "...via base class pointers..." << endl;
    Base* bp = &d;
    bp->a();
    bp->b();
    bp->c();
    //d.c(false);
}
