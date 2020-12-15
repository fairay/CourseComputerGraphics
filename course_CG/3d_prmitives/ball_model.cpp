#include "ball_model.h"


BallModel::BallModel(QRgb color, double r, const Point& center)
{
    _color = color;
    _r = r;
    _center = center;

    size_t lvl_n = static_cast<size_t>(2*r / MESH_STEP);
    size_t poly_n = lvl_n*2;
    double lvl_step = 2*r / lvl_n;
    lvl_n += 1;
    double h = -r;

    add_vertex(Point(_center.x, _center.y - r, _center.z));
    size_t v_count = 1;
    h += lvl_step/2;

    _add_vertex_row(h, poly_n);
    for (size_t i=0; i<poly_n; i++)
    {
        add_side(color, {0, i+1, (i+1) % poly_n + 1});
        // add_side(qRgb(0, 255, 0), {0, i+1, (i+1) % poly_n + 1});
    }
    h += lvl_step;
    v_count += poly_n;

    for (size_t lvl=2; lvl < lvl_n; lvl++)
    {
        _add_vertex_row(h, poly_n);
        for (size_t i=0; i<poly_n; i++)
        {
            vector<size_t> i_arr = {v_count-poly_n + i,
                                    // v_count-poly_n + (i+1)%poly_n,
                                    v_count + i,
                                    v_count + (i+1)%poly_n};
            add_side(color, i_arr);
            i_arr = {v_count-poly_n + i,
                     v_count-poly_n + (i+1)%poly_n,
//                     v_count + i,
                     v_count + (i+1)%poly_n};
            add_side(color, i_arr);
        }
        h += lvl_step;
        v_count += poly_n;
    }

    add_vertex(Point(_center.x, _center.y + r, _center.z));
    for (size_t i=0; i<poly_n; i++)
    {
        vector<size_t> i_arr = {v_count,
                                v_count-poly_n + (i),
                                v_count-poly_n + (i+1)%poly_n};
        add_side(color, i_arr);
    }

    this->normalize_vertexes();
}
BallModel::~BallModel() {}

void BallModel::_add_vertex_row(double h, size_t vertex_n)
{
    double row_r = sqrt(_r*_r - h*h);
    double angle_step = PI * 2 / vertex_n;
    double a = 0;

    for (size_t i=0; i < vertex_n; i++, a+= angle_step)
    {
        add_vertex(Point(_center.x + row_r*cos(a),
                         _center.y + h,
                         _center.z + row_r*sin(a)));
    }
}
