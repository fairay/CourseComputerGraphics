#ifndef UPDATER_H
#define UPDATER_H

#include "objects/cue_ball.h"
#include "rail_contour.h"

#define MAX_SPEED 1.0 * 1000

class Updater
{
public:
    Updater();
    ~Updater();

    void reset();
    void update(double dt);
    void make_hit(const Point& dest_p, double power);

    void add_ball(const shared_ptr<CueBall>& ball);
    void add_borders(const Point& min_p, const Point& max_p);
    void add_long_rail(Point p1, Point p2, Point p3, Point p4);
    void add_short_rail(Point p1, Point p2);

    bool is_out(const Point& p);
    bool is_motionless();
    bool is_scored(const CueBall& ball);

    Point get_min_point();
    Point get_max_point();

private:
    Point _min_p, _max_p;
    double mu=40;
    std::vector<shared_ptr<CueBall>> _active;
    std::vector<shared_ptr<CueBall>> _scored;
    std::vector<RailContour> _rails;

    void _move_ball(shared_ptr<CueBall>& ball, double dt);
    void _detect_scored();
    bool _is_out(shared_ptr<CueBall>& ball);
    bool _is_out(const Point& p);

    void _collide_rail(CueBall& ball, const Point& col_p);
    void _collide_balls(CueBall& ball1, CueBall& ball2);
};

#endif // UPDATER_H
