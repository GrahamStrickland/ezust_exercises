#include "point3.h"
#include <iostream>

int main() {
    Point3 pt1(1.2, 3.4, 5.6);
    const Point3 pt2(7.8, 9.1, 6.4);

    double d;
    d = pt2[2];
    std::cout << d << std::endl;
    d = pt1[0];
    std::cout << d << std::endl;
    d = pt1[3];
    std::cout << d << std::endl;
    pt1[2] = 8.7;
    std::cout << pt1 << std::endl;
    //  pt2[2] = 'd';
    std::cout << pt2 << std::endl;

    return 0;
}
