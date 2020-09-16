#ifndef CUE_BALL_H
#define CUE_BALL_H

#include "simple_object.h"
#include "3d_prmitives/ball_model.h"

class CueBall: public VisibleObject
{
public:
    CueBall(const Point& pos, double r, QRgb color_=QColor(Qt::red).rgba());
    explicit CueBall(const CueBall& other);
    virtual ~CueBall();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
    double _r;
};


#endif // CUE_BALL_H
