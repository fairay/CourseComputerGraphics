#ifndef BORDERS_H
#define BORDERS_H

#include "3d_prmitives/model.h"

class LongSkirting: public Model
{
public:
    LongSkirting(QRgb color, const Point& cor_p, const Point& mid_p,
                 double hu, double hd, double w, double R);
    virtual ~LongSkirting();

protected:
    QRgb _color;

    void _set_center(const Point& cor_p, const Point& mid_p, double w);
};

class ShortSkirting: public Model {
public:
    ShortSkirting(QRgb color, const Point& cor_p, const Point& mid_p,
                 double hu, double hd, double w, double R);
    virtual ~ShortSkirting();

protected:
    QRgb _color;

    void _set_center(const Point& cor_p, const Point& mid_p, double w);
};


#endif // BORDERS_H
