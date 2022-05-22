#ifndef POINT3_H
#define POINT3_H

#include <iostream>

class Point3 {
public:
    friend std::ostream& operator<<(std::ostream& out, const Point3& v);
        // Overlaoded stream insertion operator

    Point3(double x = 0, double y = 0, double z = 0);
        // Constructor with default values

    double& operator[](int index);
        // Overloaded index operator
        // Precondition: 0 <= index < 3
        // Postcondition: Returned coordinate at index
        //  or zero if out of range

    const double& operator[](int index) const;
        // Overloaded const index operator
        // Precondition: 0 <= index < 3
        // Postcondition: Returned coordinate at index
        //  or zero if out of range

    Point3 operator+(const Point3& v) const;
        // Overloaded addition operator
        // Postcondition: Returns component-wise sum of calling vector
        //  and vector v

    Point3 operator-(const Point3& v) const;
        // Overloaded subtraction operator
        // Postcondition: Returns component-wise difference between 
        //  calling vector and vector v

    Point3 operator*(double s) const;
        // Overloaded scalar multiplication operator
        // Postcondition: Returns calling vector multiplied by scalar s

private:
    static const int cm_Dim = 3;
    double m_Coord[cm_Dim];
};

#endif // POINT3_H
