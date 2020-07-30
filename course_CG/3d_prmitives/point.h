#ifndef POINT_H
#define POINT_H


class Point
{
public:
    double x, y, z;

    Point();
    Point(double x_, double y_, double z_);
    Point(const Point& other);
    ~Point();
};



#endif // POINT_H
