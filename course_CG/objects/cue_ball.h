#ifndef CUE_BALL_H
#define CUE_BALL_H

#include "simple_object.h"
#include "3d_prmitives/ball_model.h"

class CueBall: public VisibleObject
{
public:
    CueBall(const Point& pos_, double r_, QRgb color_=QColor(Qt::red).rgba(), bool is_main=false);
    explicit CueBall(const CueBall& other);
    virtual ~CueBall();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

    bool is_main();
    void move(const Vector& v);

    void set_ptr(const shared_ptr<CueBall>& _self_ptr);
    shared_ptr<CueBall> get_ptr();

    const double r;
    Point pos;
    Vector v;

private:
    QRgb _color;
    shared_ptr<CueBall> _self_ptr;
    bool _is_main;
};


#endif // CUE_BALL_H
