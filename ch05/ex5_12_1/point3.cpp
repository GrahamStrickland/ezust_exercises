#include "point3.h"
#include <cassert>

std::ostream& operator<<(std::ostream& out, const Point3& v)
{
    out << '(' << v[0] << ", " << v[1] << ", "
        << v[2] << ')';
    return out;
}

Point3::Point3(double x, double y, double z)
{
    m_Coord[0] = x;
    m_Coord[1] = y;
    m_Coord[2] = z;
}

const double& Point3::operator[](int index) const 
{
    assert(index >= 0 && index < cm_Dim);
    
    return m_Coord[index];
}

double& Point3::operator[](int index) 
{
    assert(index >= 0 && index < cm_Dim);

    return m_Coord[index];
}

Point3 Point3::operator+(const Point3& v) const
{
    return Point3(m_Coord[0] + v[0], m_Coord[1] + v[1],
            m_Coord[2] + v[2]);
}

Point3 Point3::operator-(const Point3& v) const
{
    return Point3(m_Coord[0] - v[0], m_Coord[1] - v[1],
            m_Coord[2] - v[2]);
}

Point3 Point3::operator*(double s) const
{
    return Point3(m_Coord[0] * s, m_Coord[1] * s,
            m_Coord[2] * s);
}
