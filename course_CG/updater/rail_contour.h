#ifndef RAIL_CONTOUR_H
#define RAIL_CONTOUR_H

#include "objects/cue_ball.h"

class RailContour
{
public:
    RailContour(Point p1, Point p2, Point p3, Point p4);
    virtual ~RailContour();

    bool find_collision(const CueBall& ball, Point& col_p);
    bool is_inside(const Point& p);
    bool is_inside(double x, double z);

private:
    std::vector<Point> _v_arr;

    Point _min_p;
    Point _max_p;
};

#endif // RAIL_CONTOUR_H
