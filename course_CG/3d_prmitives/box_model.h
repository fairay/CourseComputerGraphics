#ifndef BOX_MODEL_H
#define BOX_MODEL_H

#include "model.h"

class BoxModel: public Model
{
public:
    BoxModel(QRgb color, const Point& p1, const Point& p2);
    virtual ~BoxModel();

protected:
    QRgb _color;

    void _set_center(const Point& p1, const Point& p2);
    Point _find_min_p(const Point& p1, const Point& p2);
    Point _find_max_p(const Point& p1, const Point& p2);
};

class DetailBox: public BoxModel
{
public:
    DetailBox(QRgb color, const Point& p1, const Point& p2);
    virtual ~DetailBox();

private:
    const int mesh_step = 600;

    void _add_point_row(const Point& up, const Point& down, double step, int n);
    void _add_poly_row(int cur_n, int row_n);
};

class SimpleBox: public BoxModel
{
public:
    SimpleBox(QRgb color, const Point& p1, const Point& p2);
    virtual ~SimpleBox();
};

#endif // BOX_MODEL_H
