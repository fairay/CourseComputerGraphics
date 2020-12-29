#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include "point.h"
#include "errors/primitives.h"

class Vector
{
public:
    double x, y, z;

    Vector();
    Vector(double x_, double y_, double z_);
    Vector(const Vector& other);
    Vector(const Point& begin, const Point& end);
    ~Vector();

    void operator+= (const Vector& other);
    Vector operator+ (const Vector& other);

    double length();
    double scalar_mult(const Vector &other);

    void normalize();
    void invert();
    void print();
};

#endif // VECTOR_H
