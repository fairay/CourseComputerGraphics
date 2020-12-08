#include "3d_prmitives/mplate.h"

PlateModel::PlateModel(QRgb color): _color(color) {}
PlateModel::~PlateModel() {}

void PlateModel::_set_center(const Point&, const Point&) {}
Point PlateModel::_find_min_p(const Point& p1, const Point& p2)
{
    Point res;
    res.x = min(p1.x, p2.x);
    res.y = min(p1.y, p2.y);
    res.z = min(p1.z, p2.z);
    return res;
}
Point PlateModel::_find_max_p(const Point& p1, const Point& p2)
{
    Point res;
    res.x = max(p1.x, p2.x);
    res.y = max(p1.y, p2.y);
    res.z = max(p1.z, p2.z);
    return res;
}


TopPlateModel::TopPlateModel(QRgb color, const Point& p1,
                             const Point& p2, double R): PlateModel (color)
{
    Point min_p = _find_min_p(p1, p2);
    Point max_p = _find_max_p(p1, p2);
    _set_center(min_p, max_p);

    int x_n = static_cast<int>(round((max_p.x - min_p.x)/_mesh_step));
    int z_n = static_cast<int>(round((max_p.z - min_p.z)/_mesh_step));
    double x_step = (max_p.x - min_p.x)/x_n;
    double z_step = (max_p.z - min_p.z)/z_n;

    Point p = min_p;
    _add_point_row(p, z_step, z_n);
    for (int i=0; i<x_n; i++)
    {
        p.x += x_step;
        _add_point_row(p, z_step, z_n);
        // _add_poly_row((z_n+1)*(2+i), z_n);
        if (i == 0 || i == x_n-1)
            _add_poly_row((z_n+1)*(2+i), z_n, true);
        else
            _add_poly_row((z_n+1)*(2+i), z_n);
    }
    size_t c_i = static_cast<size_t>((z_n+1)*(1+x_n));
    size_t zn = static_cast<size_t>(z_n);
    const double cf = sqrt(3) / 2; // cos(30)

    add_vertex(Point(min_p.x,       min_p.y, min_p.z+R));
    add_vertex(Point(min_p.x+R/2,   min_p.y, min_p.z+cf*R));
    add_vertex(Point(min_p.x+cf*R,  min_p.y, min_p.z+R/2));
    add_vertex(Point(min_p.x+R,     min_p.y, min_p.z));

    add_side(color, {c_i, 1, zn+2, c_i+1});
    add_side(color, {c_i+1, c_i+2, zn+2});
    add_side(color, {c_i+3, zn+1, zn+2, c_i+2});

    c_i += 4;
    add_vertex(Point(min_p.x,       min_p.y, max_p.z-R));
    add_vertex(Point(min_p.x+R/2,   min_p.y, max_p.z-cf*R));
    add_vertex(Point(min_p.x+cf*R,  min_p.y, max_p.z-R/2));
    add_vertex(Point(min_p.x+R,     min_p.y, max_p.z));

    add_side(color, {c_i, zn-1, 2*zn, c_i+1});
    add_side(color, {c_i+1, c_i+2, 2*zn});
    add_side(color, {c_i+2, 2*zn, 2*zn+1, c_i + 3});


    c_i += 4;
    size_t max_i = static_cast<size_t>((z_n+1)*(1+x_n));

    add_vertex(Point(max_p.x,       min_p.y, min_p.z+R));
    add_vertex(Point(max_p.x-R/2,   min_p.y, min_p.z+cf*R));
    add_vertex(Point(max_p.x-cf*R,  min_p.y, min_p.z+R/2));
    add_vertex(Point(max_p.x-R,     min_p.y, min_p.z));


    add_side(color, {c_i, max_i-zn, max_i-zn*2-1, c_i+1});
    add_side(color, {c_i+1, c_i+2, max_i-zn*2-1});
    add_side(color, {c_i+3, max_i-zn*2-2, max_i-zn*2-1, c_i+2});

    c_i += 4;
    add_vertex(Point(max_p.x,       min_p.y, max_p.z-R));
    add_vertex(Point(max_p.x-R/2,   min_p.y, max_p.z-cf*R));
    add_vertex(Point(max_p.x-cf*R,  min_p.y, max_p.z-R/2));
    add_vertex(Point(max_p.x-R,     min_p.y, max_p.z));

    add_side(color, {c_i, max_i-2, max_i-zn-3, c_i+1});
    add_side(color, {c_i+1, c_i+2, max_i-zn-3});
    add_side(color, {c_i+2, max_i-zn-3, max_i-zn-2, c_i+3});

    normalize_vertexes();
}
TopPlateModel::~TopPlateModel() {}

void TopPlateModel::_set_center(const Point& p1, const Point& p2)
{
    _center.x = (p1.x + p2.x)/2;
    _center.y = p1.y - 100;
    _center.z = (p1.z + p2.z)/2;
}


void TopPlateModel::_add_point_row(const Point& min_p, double step, int n)
{
    Point p = min_p;
    for (int i=0; i<=n; i++)
    {
        add_vertex(p);
        p.z += step;
    }
}

void TopPlateModel::_add_poly_row(int cur_n, int row_n, bool is_edge)
{
    size_t up1 = cur_n - 2*(row_n+1);
    size_t up2 = cur_n - (row_n+1);

    for (int i=0; i<row_n; i++)
    {
        size_t temp_3 = up1+1, temp_4 =up2+1;
        if (!(is_edge && (i==0 || i==row_n-1)))
            add_side(_color, {up1, up2, temp_4, temp_3});
        up1 = temp_3;  up2 = temp_4;
    }
}

