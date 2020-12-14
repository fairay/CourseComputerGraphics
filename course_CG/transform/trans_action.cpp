#include "trans_action.h"

Action::Action() {}
Action::~Action() {}

using namespace transform;

Move::Move(const Vector& v): _delta(v) {}
Move::Move(double dx, double dy, double dz):
    _delta(dx, dy, dz) {}
Move::~Move() {}

void Move::rotate(const Vector& v)
{
    Vector v_copy{-v.x, -v.y, v.z};
    Rotate act(v_copy);
    act.execute(_delta);
}

void Move::execute(double& x, double& y, double& z)
{
    x += _delta.x;
    y += _delta.y;
    z += _delta.z;
}
void Move::execute(Vertex& p)
{
    p.x += _delta.x;
    p.y += _delta.y;
    p.z += _delta.z;
}
void Move::execute(Point& p)
{
    p.x += _delta.x;
    p.y += _delta.y;
    p.z += _delta.z;
}
void Move::execute(Vector&)
{

}
void Move::execute(Camera &p)
{
    this->execute(p.get_pos());
}


Rotate::Rotate(const Vector& v):
    _c()
{
    _dir.x = (v.x);
    _dir.y = (v.y);
    _dir.z = (v.z);
}
Rotate::Rotate(const Point& p, const Vector& v):
    _c(p)
{
    _dir.x = (v.x);
    _dir.y = (v.y);
    _dir.z = (v.z);
}
Rotate::~Rotate() {}

void Rotate::to_radians()
{
    _dir.x = _to_radians(_dir.x);
    _dir.y = _to_radians(_dir.y);
    _dir.z = _to_radians(_dir.z);
}

void Rotate::rotate(const Vector&)
{
}

void Rotate::execute(double& x, double& y, double& z)
{
    rotate_x(x, y, z);
    rotate_y(x, y, z);
    rotate_z(x, y, z);
}
void Rotate::execute(Vertex& p)
{
    rotate_x(p.x, p.y, p.z);
    rotate_y(p.x, p.y, p.z);
    rotate_z(p.x, p.y, p.z);
}
void Rotate::execute(Point& p)
{
    rotate_x(p.x, p.y, p.z);
    rotate_y(p.x, p.y, p.z);
    rotate_z(p.x, p.y, p.z);
}
void Rotate::execute(Vector& p)
{
    rotate_ox(p.x, p.y, p.z);
    rotate_oy(p.x, p.y, p.z);
    rotate_oz(p.x, p.y, p.z);
}
void Rotate::execute(Camera &p)
{
    Vector& v = p.get_dir();
    v.x += _dir.x;
    v.y += _dir.y;
    v.z += _dir.z;
    p.get_dir().print();
}

void Rotate::rotate_x(double&, double& y_, double& z_)
{
    double y, z;
    y = _c.y + (y_-_c.y)*cos(_dir.x) + (z_-_c.z)*sin(_dir.x);
    z = _c.z - (y_-_c.y)*sin(_dir.x) + (z_-_c.z)*cos(_dir.x);

    y_ = y;
    z_ = z;
}
void Rotate::rotate_y(double& x_, double&, double& z_)
{
    double x, z;
    x = _c.x + (x_-_c.x)*cos(_dir.y) - (z_-_c.z)*sin(_dir.y);
    z = _c.z + (x_-_c.x)*sin(_dir.y) + (z_-_c.z)*cos(_dir.y);

    x_ = x;
    z_ = z;
}
void Rotate::rotate_z(double& x_, double& y_, double&)
{
    double y, x;
    x = _c.x + (x_-_c.x)*cos(_dir.z) + (y_-_c.y)*sin(_dir.z);
    y = _c.y - (x_-_c.x)*sin(_dir.z) + (y_-_c.y)*cos(_dir.z);

    x_ = x;
    y_ = y;
}

void Rotate::rotate_ox(double&, double& y_, double& z_)
{
    double y, z;
    y = y_*cos(_dir.x) + z_*sin(_dir.x);
    z = -y_*sin(_dir.x) + z_*cos(_dir.x);

    y_ = y;
    z_ = z;
}
void Rotate::rotate_oy(double& x_, double&, double& z_)
{
    double x, z;
    x = x_*cos(_dir.y) - z_*sin(_dir.y);
    z = x_*sin(_dir.y) + z_*cos(_dir.y);

    x_ = x;
    z_ = z;
}
void Rotate::rotate_oz(double& x_, double& y_, double&)
{
    double y, x;
    x = x_*cos(_dir.z) + y_*sin(_dir.z);
    y = -x_*sin(_dir.z) + y_*cos(_dir.z);

    x_ = x;
    y_ = y;
}

double Rotate::_to_radians(double a)
{
    return a * PI / 180;
}



Scale::Scale(const Vector& v): _c(), _sc(v) {}
Scale::Scale(const Point& p, const Vector& v): _c(p), _sc(v) {}
Scale::~Scale() {}

void Scale::rotate(const Vector&)
{
}

void Scale::execute(double& x, double& y, double& z)
{
    x = _c.x + _sc.x*(x - _c.x);
    y = _c.y + _sc.y*(y - _c.y);
    z = _c.z + _sc.z*(z - _c.z);
}
void Scale::execute(Vertex &p)
{
    p.x = _c.x + _sc.x*(p.x - _c.x);
    p.y = _c.y + _sc.y*(p.y - _c.y);
    p.z = _c.z + _sc.z*(p.z - _c.z);
    this->execute(p.n);
}
void Scale::execute(Point &p)
{
    p.x = _c.x + _sc.x*(p.x - _c.x);
    p.y = _c.y + _sc.y*(p.y - _c.y);
    p.z = _c.z + _sc.z*(p.z - _c.z);
}
void Scale::execute(Vector &p)
{
    p.x *= _sc.x;
    p.y *= _sc.y;
    p.z *= _sc.z;
}
void Scale::execute(Camera &p)
{
    this->execute(p.get_pos());
}
