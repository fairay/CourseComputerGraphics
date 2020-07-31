#ifndef BOX_MODEL_H
#define BOX_MODEL_H

#include "model.h"

class BoxModel: public Model
{
public:
    BoxModel(QRgb color, const Point& p1, const Point& p2);
    ~BoxModel();

private:
    QRgb _color;

    void _set_center(const Point& p1, const Point& p2);
    Point _find_min_p(const Point& p1, const Point& p2);
    Point _find_max_p(const Point& p1, const Point& p2);
};

#endif // BOX_MODEL_H
