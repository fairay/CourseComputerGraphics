#ifndef MPLATE_H
#define MPLATE_H

#include "model.h"

class PlateModel: public Model
{
public:
    PlateModel(QRgb color);
    virtual ~PlateModel();

protected:
    QRgb _color;
    double _mesh_step = 400;

    void _set_center(const Point& p1, const Point& p2);
    Point _find_min_p(const Point& p1, const Point& p2);
    Point _find_max_p(const Point& p1, const Point& p2);
};


class TopPlateModel: public PlateModel
{
public:
    TopPlateModel(QRgb color, const Point& p1, const Point& p2, double R);
    virtual ~TopPlateModel();

protected:
    void _set_center(const Point& p1, const Point& p2);
    void _add_point_row(const Point& min_p, double step, int n);
    void _add_poly_row(int cur_n, int row_n, bool is_edge=false);
};


class BottomPlateModel: public PlateModel
{
public:
    BottomPlateModel(QRgb color, const Point& p1, const Point& p2);
    virtual ~BottomPlateModel();

protected:
    void _set_center(const Point& p1, const Point& p2);
};

#endif // MPLATE_H
