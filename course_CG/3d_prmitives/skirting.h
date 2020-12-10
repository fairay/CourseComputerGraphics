#ifndef BORDERS_H
#define BORDERS_H

#include "3d_prmitives/model.h"

class LongSkirting: public Model
{
public:
    LongSkirting(QRgb color, const Point& cor_p, const Point& mid_p,
                 double hu, double hd, double w, double R);
    virtual ~LongSkirting();

    Point get_cor_top() const;
    Point get_cor_back() const;
    Point get_mid_top() const;
    Point get_mid_back() const;
protected:
    QRgb _color;
    Point _cor_top, _cor_back, _mid_top, _mid_back;
    void _set_center(const Point& cor_p, const Point& mid_p, double w);
};

class ShortSkirting: public Model {
public:
    ShortSkirting(QRgb color, const Point& cor_p, const Point& mid_p,
                 double hu, double hd, double w, double R);
    virtual ~ShortSkirting();

    Point get_cor_top() const;
    Point get_cor_back() const;
    Point get_mid_top() const;
    Point get_mid_back() const;
protected:
    QRgb _color;
    Point _cor_top, _cor_back, _mid_top, _mid_back;
    void _set_center(const Point& cor_p, const Point& mid_p, double w);
};


#endif // BORDERS_H
