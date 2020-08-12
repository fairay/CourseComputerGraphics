#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "3d_prmitives/point.h"
#include "3d_prmitives/vertex.h"
#include "3d_prmitives/vector.h"
#include "3d_prmitives/ball_model.h"
#include "objects/camera.h"
#include "math.h"

class Action
{
public:
    Action();
    virtual ~Action() = 0;

    virtual void execute(double& x, double& y, double& z) = 0;
    virtual void execute(Camera& p) = 0;
    virtual void execute(Vertex& p) = 0;
    virtual void execute(Point& p) = 0;
    virtual void execute(Vector& p) = 0;
};

namespace transform
{

class Move: public Action
{
public:
    Move(const Vector& v);
    Move(double dx, double dy, double dz);
    virtual ~Move();

    virtual void execute(double& x, double& y, double& z);
    virtual void execute(Camera& p);
    virtual void execute(Vertex& p);
    virtual void execute(Point& p);
    virtual void execute(Vector& p);
private:
    Vector _delta;
};

class Rotate: public Action
{
public:
    Rotate(const Vector& v);
    Rotate(const Point& p, const Vector& v);
    virtual ~Rotate();

    virtual void execute(double& x, double& y, double& z);
    virtual void execute(Camera& p);
    virtual void execute(Vertex& p);
    virtual void execute(Point& p);
    virtual void execute(Vector& p);
private:
    Point _c;
    Vector _dir;

    void rotate_x(double& x, double& y, double& z);
    void rotate_y(double& x, double& y, double& z);
    void rotate_z(double& x, double& y, double& z);

    void rotate_ox(double& x, double& y, double& z);
    void rotate_oy(double& x, double& y, double& z);
    void rotate_oz(double& x, double& y, double& z);

    double _to_radians(double a);
};

class Scale: public Action
{
public:
    Scale(const Vector& v);
    Scale(const Point& p, const Vector& v);
    virtual ~Scale();

    virtual void execute(double& x, double& y, double& z);
    virtual void execute(Camera& p);
    virtual void execute(Vertex& p);
    virtual void execute(Point& p);
    virtual void execute(Vector& p);
private:
    Point _c;
    Vector _sc;
};

}; // transform

#endif // TRANSFORMATION_H
