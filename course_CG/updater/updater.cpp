#include "updater.h"

using namespace std;

Updater::Updater() {}
Updater::~Updater() {}

void Updater::reset()
{
    _active.clear();
    _scored.clear();
    _rails.clear();
}
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

    _detect_scored();
}

void Updater::make_hit(const Point& dest_p, double power)
{
    shared_ptr<CueBall> ball;
    for (size_t i=0; i<_active.size(); i++)
        if (_active[i]->is_main())
        {
            ball = _active[i];
            break;
        }
    if (!ball)
        return;

    Vector dir(ball->pos, dest_p);
    dir.y = 0;
    dir.normalize();

    double speed = power*MAX_SPEED;
    ball->v.x = dir.x*speed;
    ball->v.z = dir.z*speed;
}

void Updater::_move_ball(shared_ptr<CueBall>& ball, double dt)
{
    Vector& v = ball->v;
    double speed = v.length();
    if (speed > 0)
    {
        ball->move(Vector(v.x*dt, 0, v.z*dt));
        ball->roll_rotate(Vector(-v.z*dt/(ball->r), 0, v.x*dt/(ball->r)));
        double slowdown = max<double>(0, 1 - (dt*mu)/speed);
        v.x *= slowdown;
        v.z *= slowdown;
    }
}

void Updater::_collide_rail(CueBall &ball, const Point& p)
{
    cout << "Collide\trail!" << endl;
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

    cout << "Collide\tballs" << endl;
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

void Updater::_detect_scored()
{
    for (auto i=_active.begin(); i < _active.end();)
    {
        if (_is_out(*i))
        {
            _scored.push_back(*i);
            _active.erase(i);
        }
        else
            i++;
    }
}

bool Updater::_is_out(shared_ptr<CueBall>& ball)
{
//    return (_min_p.x > ball->pos.x || _max_p.x < ball->pos.x) ||
//           (_min_p.z > ball->pos.z || _max_p.z < ball->pos.z);
    return _is_out(ball->pos);
}
bool Updater::_is_out(const Point& p)
{
    return (_min_p.x > p.x || _max_p.x < p.x) ||
           (_min_p.z > p.z || _max_p.z < p.z);
}

bool Updater::is_out(const Point& p) { return _is_out(p); }
bool Updater::is_motionless()
{
    for (size_t i=0; i<_active.size(); i++)
        if (_active[i]->v.length() > 1e-5)
            return false;
    return true;
}
bool Updater::is_scored(const CueBall& ball)
{
    for (auto sc_ball : _scored)
        if (sc_ball->pos.distance2d(ball.pos) < 1e-3)
            return true;
    return false;
}

Point Updater::get_min_point() { return _min_p; }
Point Updater::get_max_point() { return _max_p; }

void Updater::add_borders(const Point& min_p, const Point& max_p)
{
    _min_p = min_p;
    _max_p = max_p;
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
