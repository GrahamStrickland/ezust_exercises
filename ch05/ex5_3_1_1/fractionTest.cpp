// Driver program to test objects of type Fraction.

#include "fraction.h"
#include <QString>
#include <QTextStream>

int main()
{
    QTextStream cout(stdout);

    Fraction f1, f2(3, 6), f3;

    // fractional arithmetic operator tests
    cout << "Testing arithmetic operators: " << endl << endl;

    f1.set(4, 5);

    f3 = f1 + f2;

    cout << f1.toString() << " + " << f2.toString()
         << " = " << f3.toString() << endl << endl;

    f3 = f1 - f2;

    cout << f1.toString() << " - " << f2.toString() 
         << " = " << f3.toString() << endl << endl;

    f3 = f1 * f2;

    cout << f1.toString() << " * " << f2.toString() 
         << " = " << f3.toString() << endl << endl;

    f3 = f1 / f2;

    cout << f1.toString() << " / " << f2.toString() 
         << " = " << f3.toString() << endl << endl;

    // set() tests
    cout << "Testing set() function: " << endl << endl;
    
    f3.set(0, 5);
    cout << "f3.set(0, 5) = " << f3.toString() << endl << endl;

    f3.set(-4, -10);
    cout << "f3.set(-4, -10) = " << f3.toString() << endl << endl;

    f3.set(10, -20);
    cout << "f3.set(10, -20) = " << f3.toString() << endl << endl;

    f3.set(-4, 15);
    cout << "f3.set(-4, 15) = " << f3.toString() << endl << endl;

    cout << f1.toString() << " is" << (f1 == f2 ? "" : " not")
         << " equal to " << f2.toString() << endl << endl;

    cout << f2.toString() << " is" << (f1 != f2 ? " not" : "")
         << " equal to " << f3.toString() << endl << endl;

    // int operand arithmetic tests
    cout << "Testing with operands of type int:" 
         << endl << endl;

    int a = 2, b = -3;

    cout << f1.toString() << " + " << b << " = " << (f1 + b).toString()
         << endl << endl;

    cout << f2.toString() << " - " << a << " = " << (f2 - a).toString()
         << endl << endl;

    cout << f3.toString() << " * " << b << " = " << (f3 * b).toString()
         << endl << endl;

    cout << f3.toString() << " / " << a << " = " << (f3 / a).toString()
         << endl << endl;

    cout << a << " + " << f1.toString() << " = " << (a + f1).toString()
         << endl << endl;

    cout << b << " - " << f2.toString() << " = " << (b - f2).toString()
         << endl << endl;

    cout << a << " * " << f1.toString() << " = " << (a * f1).toString()
         << endl << endl;

    cout << b << " / " << f2.toString() << " = " << (b / f2).toString()
         << endl << endl;

    // double operand arithmetic tests
    cout << "Testing with operands of type double:" 
         << endl << endl;

    double e = 2.71, p = -3.14;

    cout << f1.toString() << " + " << e << " = " << (f1 + e).toString()
         << endl << endl;

    cout << f2.toString() << " - " << p << " = " << (f2 - p).toString()
         << endl << endl;

    cout << f3.toString() << " * " << e << " = " << (f3 * e).toString()
         << endl << endl;

    cout << f3.toString() << " / " << p << " = " << (f3 / p).toString()
         << endl << endl;

    cout << p << " + " << f1.toString() << " = " << (p + f1).toString()
         << endl << endl;

    cout << e << " - " << f2.toString() << " = " << (e - f2).toString()
         << endl << endl;

    cout << p << " * " << f1.toString() << " = " << (p * f1).toString()
         << endl << endl;

    cout << e << " / " << f2.toString() << " = " << (e / f2).toString()
         << endl << endl;

    return 0;
}
