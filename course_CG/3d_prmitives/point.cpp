#include "point.h"
#include "vertex.h"

Point::Point() {}
Point::Point(double x_, double y_, double z_):
    x(x_), y(y_), z(z_) {}
Point::Point(const Point& other):
    x(other.x), y(other.y), z(other.z) {}
Point::~Point() {}

void Point::rotate(const Point& c, const Vector& v)
{
    rotate_ox(c, v.x);
    rotate_oy(c, v.y);
    rotate_oz(c, v.z);
}

void Point::rotate_ox(const Point& c, double a)
{
    double y1 = c.y + (y-c.y)*cos(a) - (z-c.z)*sin(a);
    double z1 = c.z + (y-c.y)*sin(a) + (z-c.z)*cos(a);
    y = y1; z = z1;
}
void Point::rotate_oy(const Point& c, double a)
{
    double x1 = c.x + (x-c.x)*cos(a) + (z-c.z)*sin(a);
    double z1 = c.z - (x-c.x)*sin(a) + (z-c.z)*cos(a);
    x = x1; z = z1;
}
void Point::rotate_oz(const Point& c, double a)
{
    double x1 = c.x + (x-c.x)*cos(a) - (y-c.y)*sin(a);
    double y1 = c.y + (x-c.x)*sin(a) + (y-c.y)*cos(a);
    x = x1; y = y1;
}


Vertex::Vertex() {}
Vertex::Vertex(double x_, double y_, double z_):
    Point(x_, y_, z_) {}
Vertex::Vertex(const Vertex& other):
    Point(other), n(other.n) {}
Vertex::Vertex(const Point& other):
    Point(other) {}
Vertex::~Vertex() {}

bool Vertex::operator == (const Vertex& other)
{
    if (fabs(this->x-other.x) < 1e-5) return false;
    else if (fabs(this->y-other.y) < 1e-5) return false;
    else if (fabs(this->z-other.z) < 1e-5) return false;
    else return true;
}

void Vertex::print()
{
    printf("Vertex: (%lf, %lf, %lf) -> \t", x, y, z);
    printf("[%lf, %lf, %lf]\n", n.x, n.y, n.z);
}

void Vertex::normalize()
{
    n.normalize();
}
