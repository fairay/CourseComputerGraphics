#ifndef VERTEX_H
#define VERTEX_H

#include "vector.h"
#include "point.h"
#include <stdio.h>

class Vertex: public Point
{
public:
    Vector n;

    Vertex();
    Vertex(double x_, double y_, double z_);
    Vertex(const Vertex& other);
    Vertex(const Point& other);
    ~Vertex();

    void print();
    void normalize();
};

#endif // VERTEX_H
