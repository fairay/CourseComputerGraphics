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
    for (size_t i=0; i<_active.size(); i++)
        for (size_t j=i+1; j<_active.size(); j++)
            _collide_balls(*_active[i], *_active[j]);
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
    cout << "Collide!" << endl;
    double d = ball.pos.distance2d(p);
    double a = ball.pos.x - p.x;
    double b = ball.pos.z - p.z;

    double p1 = (a*b) / (d*d);
    double p2 = (a*a) / (d*d);
    double p3 = (b*b) / (d*d);

    double d1 = ball.v.z * p1 + ball.v.x * p2;
    double d2 = ball.v.x * p1 + ball.v.z * p3;

    // Update speed
    ball.v.x -= d1*2;
    ball.v.z -= d2*2;

    // Update position
    p3 = ball.r - d;
    p1 = p3 * (a/d);
    p2 = p3 * (b/d);

//    ball.pos.x += p1;
//    ball.pos.z += p2;
    ball.move(Vector(p1, 0, p2));
}

void Updater::_collide_balls(CueBall &ball1, CueBall &ball2)
{
    double dist = ball1.pos.distance2d(ball2.pos);
    if (dist > ball1.r*2)
        return;

    double vel1 = ball1.v.length();
    double vel2 = ball2.v.length();

    double a = ball1.pos.x - ball2.pos.x;
    double b = ball1.pos.z - ball2.pos.z;

    double p1, p2, p3;
    if (vel1 + vel2 > 1e-5)
    {
        p1 = (a*b) / (dist*dist);
        p2 = (a*a) / (dist*dist);
        p3 = (b*b) / (dist*dist);

        double d1 = (ball1.v.z - ball2.v.z)*p1 + (ball1.v.x - ball2.v.x)*p2;
        double d2 = (ball1.v.x - ball2.v.x)*p1 + (ball1.v.z - ball2.v.z)*p3;

        ball1.v.x -= d1;    ball1.v.z -= d2;
        ball2.v.x += d1;    ball2.v.z += d2;
    }

    p3 = ball1.r*2 - dist;
    p1 = p3 * (a/dist);
    p2 = p3 * (b/dist);

    double k;
    if (vel1 + vel2 > 1e-5) k = vel1 / (vel1 + vel2);
    else                    k = 0.5;

    // ball1.pos.x += p1*k;        ball1.pos.z += p2*k;
    // ball2.pos.x -= p1*(1-k);    ball2.pos.z -= p2*(1-k);
    ball1.move(Vector(p1*k, 0, p2*k));
    ball2.move(Vector(p1*(k-1), 0, p2*(k-1)));
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
