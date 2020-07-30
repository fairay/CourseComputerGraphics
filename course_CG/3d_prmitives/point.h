#ifndef POINT_H
#define POINT_H

#include "vector.h"

class Point
{
public:
    double x, y, z;

    Point();
    Point(double x_, double y_, double z_);
    Point(const Point& other);
    ~Point();

};

class Vertex: public Point
{
public:
    Vector n;

    Vertex();
    Vertex(double x_, double y_, double z_);
    Vertex(const Vertex& other);
    Vertex(const Point& other);
    ~Vertex();
};

#endif // POINT_H
