#include "point.h"
#include "vertex.h"

Point::Point() {}
Point::Point(double x_, double y_, double z_):
    x(x_), y(y_), z(z_) {}
Point::Point(const Point& other):
    x(other.x), y(other.y), z(other.z) {}
Point::~Point() {}


Vertex::Vertex() {}
Vertex::Vertex(double x_, double y_, double z_):
    Point(x_, y_, z_) {}
Vertex::Vertex(const Vertex& other):
    Point(other), n(other.n) {}
Vertex::Vertex(const Point& other):
    Point(other) {}
Vertex::~Vertex() {}

void Vertex::print()
{
    printf("Vertex: (%lf, %lf, %lf) -> \t", x, y, z);
    printf("[%lf, %lf, %lf]\n", n.x, n.y, n.z);
}
