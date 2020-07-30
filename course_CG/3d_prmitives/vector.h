#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

class Vector
{
public:
    double x, y, z;

    Vector();
    Vector(double x_, double y_, double z_);
    Vector(const Vector& other);
    ~Vector();

    void operator+= (const Vector& other);
    Vector operator+ (const Vector& other);

    double length();
    void normalize();
};

#endif // VECTOR_H
