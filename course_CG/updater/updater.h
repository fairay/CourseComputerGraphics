#ifndef UPDATER_H
#define UPDATER_H

#include "objects/cue_ball.h"
#include "rail_contour.h"

class Updater
{
public:
    Updater();
    ~Updater();

    void update(double dt);

    void add_ball(const shared_ptr<CueBall>& ball);
    void add_long_rail(Point p1, Point p2, Point p3, Point p4);
    void add_short_rail(Point p1, Point p2);

private:
    double mu=0;
    std::vector<shared_ptr<CueBall>> _active;
    std::vector<shared_ptr<CueBall>> _scored;
    std::vector<RailContour> _rails;

    void _move_ball(shared_ptr<CueBall>& ball, double dt);

    void _collide_rail(CueBall& ball, const Point& col_p);
    void _collide_balls(CueBall& ball1, CueBall& ball2);
};

#endif // UPDATER_H
