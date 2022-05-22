#ifndef THING_H
#define THING_H

#include <iostream>
#include <string>
using namespace std;

class Thing {
public:
    Thing(int n) : m_Num(n) {

    }
    ~Thing() {
        cout << "destructor called: "
             << m_Num << endl;
    }

private:
    string m_String;
    int m_Num;
};
#endif // THING_H
