#ifndef BALL_MODEL_H
#define BALL_MODEL_H

#include "model.h"
#define MESH_STEP 25
#define PI 3.14159265359

class BallModel: public Model
{
public:
    BallModel(QRgb color, double r, const Point& center = Point(0,0,0));
    virtual ~BallModel();

private:
    QRgb _color;
    double _r;

    void _add_vertex_row(double h, size_t vertex_n);
};

#endif // BALL_MODEL_H
