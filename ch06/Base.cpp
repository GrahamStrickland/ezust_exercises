#include <iostream>
#include "Base.h"

using namespace std;

Base::Base() {
    cout << "Base::Base()" << endl;
    a();
    c();
}

void Base::c(bool condition) {
    cout << "Base::c()" << endl;
}

void Base::a() {
    cout << "Base::a()" << endl;
    b();
}

void Base::b() {
    cout << "Base::b()" << endl;
}

Derived::Derived() {
    cout << "Derived::Derived()" << endl;
}

void Derived::a() {
    cout << "Derived::a()" << endl;
    c();
}

void Derived::b() {
    cout << "Derived::b()" << endl;
}

void Derived::c() {
    cout << "Derived::c()" << endl;
}
