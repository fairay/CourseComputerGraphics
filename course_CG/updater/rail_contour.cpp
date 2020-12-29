#include "rail_contour.h"

Point find_min_p(const Point& p1, const Point& p2)
{
    Point res;
    res.x = min(p1.x, p2.x);
    res.y = min(p1.y, p2.y);
    res.z = min(p1.z, p2.z);
    return res;
}
Point find_max_p(const Point& p1, const Point& p2)
{
    Point res;
    res.x = max(p1.x, p2.x);
    res.y = max(p1.y, p2.y);
    res.z = max(p1.z, p2.z);
    return res;
}

RailContour::RailContour(Point p1, Point p2, Point p3, Point p4)
{
    _v_arr.push_back(p1);
    _v_arr.push_back(p2);
    _v_arr.push_back(p3);
    _v_arr.push_back(p4);

    _min_p = find_min_p(p1, p4);
    _max_p = find_max_p(p1, p4);
}
RailContour::~RailContour() {}

bool RailContour::find_collision(const CueBall& ball, Point& col_p)
{
    /*
     *  ^
     * z\
     *  \
     *  \
     *  *------->
     *          x
    */

    const Point& p = ball.pos;
    double r = ball.r;

    if (is_inside(p.x + r, p.z))    // left side
        col_p = Point(_min_p.x, _min_p.y, p.z);
    else if (is_inside(p.x - r, p.z))    // right side
        col_p = Point(_max_p.x, _min_p.y, p.z);
    else if (is_inside(p.x, p.z + r))    // top side
        col_p = Point(p.x, _min_p.y, _min_p.z);
    else if (is_inside(p.x, p.z - r))    // bottom side
        col_p = Point(p.x, _min_p.y, _max_p.z);
    else
    {
        for (auto v: _v_arr)
            if (v.distance2d(p) < r)
            {
                col_p = v;
                return true;
            }
        return false;
    }

    return true;
}

bool RailContour::is_inside(const Point& p)
{
    return is_inside(p.x, p.z);
}
bool RailContour::is_inside(double x, double z)
{
    return (_min_p.x < x && _max_p.x > x) &&
            (_min_p.z < z && _max_p.z > z);
}
