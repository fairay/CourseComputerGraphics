#include "updater.h"

using namespace std;

Updater::Updater() {}
Updater::~Updater() {}

void Updater::update(double dt)
{
    for (size_t i=0; i<_active.size(); i++)
    {
        _move_ball(_active[i], dt);

        Point col_p;
        for (auto rail: _rails)
            if (rail.find_collision(*_active[i], col_p))
                _collide_rail(*_active[i], col_p);
    }
}

void Updater::_move_ball(shared_ptr<CueBall>& ball, double dt)
{
    Vector& v = ball->v;
    double speed = v.length();
    if (speed > 0)
    {
        ball->move(Vector(v.x*dt, 0, v.z*dt));
        double slowdown = max<double>(0, 1 - (dt*mu)/speed);
        v.x *= slowdown;
        v.z *= slowdown;
    }
}

void Updater::_collide_rail(CueBall &ball, const Point& p)
{
    double d = ball.pos.distance2d(p);
    double a = ball.pos.x - p.x;
    double b = ball.pos.z - p.z;

    double p1 = a*b / (d*d);
    double p2 = a*a / (d*d);
    double p3 = b*b / (d*d);

    double d1 = ball.v.z * p1 + ball.v.x * p2;
    double d2 = ball.v.x * p1 + ball.v.z * p3;

    ball.v.x -= d1*2;
    ball.v.z -= d2*2;
}
void Updater::_collide_balls(shared_ptr<CueBall>& ball1, shared_ptr<CueBall>& ball2)
{

}

void Updater::add_ball(const shared_ptr<CueBall> &ball)
{
    _active.push_back(ball);
}

void Updater::add_long_rail(Point p1, Point p2, Point p3, Point p4)
{
    _rails.push_back(RailContour(p1, p2, p3, p4));
}

void add_short_rail(Point, Point) {}
