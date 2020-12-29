#include "box_model.h"

BoxModel::BoxModel(QRgb color, const Point& p1, const Point& p2)
{
    _color = color;
    _set_center(p1, p2);
}
BoxModel::~BoxModel() {}

void BoxModel::_set_center(const Point& p1, const Point& p2)
{
    _center.x = (p1.x + p2.x)/2;
    _center.y = (p1.y + p2.y)/2;
    _center.z = (p1.z + p2.z)/2;
}
Point BoxModel::_find_min_p(const Point& p1, const Point& p2)
{
    Point res;
    res.x = min(p1.x, p2.x);
    res.y = min(p1.y, p2.y);
    res.z = min(p1.z, p2.z);
    return res;
}
Point BoxModel::_find_max_p(const Point& p1, const Point& p2)
{
    Point res;
    res.x = max(p1.x, p2.x);
    res.y = max(p1.y, p2.y);
    res.z = max(p1.z, p2.z);
    return res;
}


DetailBox::DetailBox(QRgb color, const Point& p1, const Point& p2):
    BoxModel(color, p1, p2)
{
    Point min_p = _find_min_p(p1, p2);
    Point max_p = _find_max_p(p1, p2);

    int x_n = static_cast<int>(round((max_p.x - min_p.x)/mesh_step));
    int z_n = static_cast<int>(round((max_p.z - min_p.z)/mesh_step));
    double x_step = (max_p.x - min_p.x)/x_n;
    double z_step = (max_p.z - min_p.z)/z_n;

    Point down = min_p;
    Point up = min_p;
    up.y = max_p.y;
    _add_point_row(up, down, z_step, z_n);
    for (int i=0; i<x_n; i++)
    {
        up.x += x_step;
        down.x += x_step;
        _add_point_row(up, down, z_step, z_n);
        _add_poly_row(((z_n+1)*2*(2+i)), z_n);
    }

    this->normalize_vertexes();
}
DetailBox::~DetailBox() {}

void DetailBox::_add_point_row(const Point& up_, const Point& down_, double step, int n)
{
    Point down = down_;
    Point up = up_;
    for (int i=0; i<=n; i++)
    {
        add_vertex(up);
        add_vertex(down);

        up.z += step;
        down.z += step;
    }
}
void DetailBox::_add_poly_row(int cur_n, int row_n)
{
    size_t up1 = cur_n - 4*(row_n + 1);
    size_t do1 = up1 + 1;
    size_t up2 = cur_n - 2*(row_n + 1);
    size_t do2 = up2 + 1;
    add_side(_color, {up1, up2, do2, do1});

    for (int i=0; i<row_n; i++)
    {
        size_t temp_3 = up1+2, temp_4 =up2+2;
        add_side(_color, {up1, up2, temp_4, temp_3});
        up1 = temp_3;  up2 = temp_4;

        temp_3 = do1+2; temp_4 = do2+2;
        add_side(_color, {do1, do2, temp_4, temp_3});
        do1 = temp_3;  do2 = temp_4;
    }

    add_side(_color, {up1, up2, do2, do1});
}



SimpleBox::SimpleBox(QRgb color, const Point& p1, const Point& p2):
    BoxModel(color, p1, p2)
{
    Point min_p = _find_min_p(p1, p2);
    Point max_p = _find_max_p(p1, p2);

    add_vertex(Point(min_p.x, min_p.y, min_p.z));
    add_vertex(Point(min_p.x, min_p.y, max_p.z));
    add_vertex(Point(min_p.x, max_p.y, max_p.z));
    add_vertex(Point(min_p.x, max_p.y, min_p.z));

    add_vertex(Point(max_p.x, min_p.y, min_p.z));
    add_vertex(Point(max_p.x, min_p.y, max_p.z));
    add_vertex(Point(max_p.x, max_p.y, max_p.z));
    add_vertex(Point(max_p.x, max_p.y, min_p.z));

    add_side(color, {0, 1, 2, 3});
    add_side(color, {4, 5, 6, 7});

    add_side(color, {0, 1, 5, 4});
    add_side(color, {1, 2, 6, 5});
    add_side(color, {2, 3, 7, 6});
    add_side(color, {3, 0, 4, 7});

    this->normalize_vertexes();
}
SimpleBox::~SimpleBox() {}
