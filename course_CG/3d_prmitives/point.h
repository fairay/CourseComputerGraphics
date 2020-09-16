#ifndef POINT_H
#define POINT_H

class Vector;

class Point
{
public:
    double x, y, z;

    Point();
    Point(double x_, double y_, double z_);
    Point(const Point& other);
    ~Point();

    void rotate(const Point& c, const Vector& v);
    void print();
    double distance(const Point& other);
private:
    void rotate_ox(const Point& c, double a);
    void rotate_oy(const Point& c, double a);
    void rotate_oz(const Point& c, double a);
};



#endif // POINT_H
