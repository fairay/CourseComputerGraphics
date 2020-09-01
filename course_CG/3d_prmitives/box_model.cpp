#include "box_model.h"

BoxModel::BoxModel(QRgb color, const Point& p1, const Point& p2)
{
    _color = color;
    _set_center(p1, p2);

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
