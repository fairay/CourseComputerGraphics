#include "vector.h"

Vector::Vector() {}
Vector::Vector(double x_, double y_, double z_):
    x(x_), y(y_), z(z_) {}
Vector::Vector(const Vector& other):
    x(other.x), y(other.y), z(other.z) {}
Vector::Vector(const Point& begin, const Point& end)
{
    x = end.x - begin.x;
    y = end.y - begin.y;
    z = end.z - begin.z;
}
Vector::~Vector() {}


void Vector::operator += (const Vector& other)
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
}
Vector Vector::operator + (const Vector& other)
{
    Vector res;
    res.x = this->x + other.x;
    res.y = this->y + other.y;
    res.z = this->z + other.z;
    return res;
}

double Vector::length()
{
    return sqrt(x*x + y*y + z*z);
}
double Vector::scalar_mult(const Vector &other)
{
    return this->x*other.x + this->y*other.y + this->z*other.z;
}

void Vector::normalize()
{
    double len = this->length();
    if (fabs(len) > 1e-5)
    {
        x /= len;
        y /= len;
        z /= len;
    }
}
void Vector::invert()
{
    x = -x;
    y = -y;
    z = -z;
}
