#include "skirting.h"

int sign_double(double n)
{
    if (n>0)
        return 1;
    else
        return -1;
}

LongSkirting::LongSkirting(QRgb color, const Point& cor_p, const Point& mid_p,
             double hu, double hd, double w, double R)
{
    _color = color;

    int xs = sign_double(cor_p.x);  // x offset sign
    int zs = sign_double(cor_p.z);  // z offset sign
    double yu = cor_p.y + hu;

    // Top vertexes
    add_vertex(Point(cor_p.x + xs*w,            yu, cor_p.z + zs*w));            // 0
    add_vertex(Point(cor_p.x + xs*R/sqrt(2),    yu, cor_p.z + zs*R/sqrt(2)));
    add_vertex(Point(cor_p.x + xs*R,            yu, cor_p.z));
    add_vertex(Point(cor_p.x - xs*R/sqrt(2),    yu, cor_p.z - zs*R*3/sqrt(2)));  // 3
    add_vertex(Point(cor_p.x + xs*w,            yu, cor_p.z));
    add_vertex(Point(cor_p.x + xs*w,            yu, cor_p.z - zs*R*3/sqrt(2)));

    add_vertex(Point(cor_p.x - xs*R/sqrt(2), yu, mid_p.z + zs*R)); // 6
    add_vertex(Point(mid_p.x + xs*R,         yu, mid_p.z + zs*R));
    add_vertex(Point(cor_p.x + xs*w,         yu, mid_p.z + zs*R));
    add_vertex(Point(mid_p.x + xs*R,         yu, mid_p.z));        // 9
    add_vertex(Point(mid_p.x + xs*w,         yu, mid_p.z));

    add_side(_color, {0, 1, 2, 4});
    add_side(_color, {2, 4, 5, 3});

    add_side(_color, {3, 5, 7, 6});
    add_side(_color, {5, 7, 8});
    add_side(_color, {7, 8, 10, 9});

    // Bottom vertexes
    double yd = cor_p.y - hd;
    double y0 = cor_p.y;
    add_vertex(Point(cor_p.x + xs*w,         yd, cor_p.z + zs*w));                    // 11
    add_vertex(Point(cor_p.x + xs*R/sqrt(2), yd, cor_p.z + zs*R/sqrt(2)));
    add_vertex(Point(cor_p.x + xs*R,         yd, cor_p.z));
    add_vertex(Point(cor_p.x - xs*R/sqrt(8), y0, cor_p.z - zs*R*3/sqrt(2)));  // 14
    add_vertex(Point(cor_p.x + xs*w,         yd, cor_p.z));
    add_vertex(Point(cor_p.x + xs*w,         yd, cor_p.z - zs*R*3/sqrt(2)));

    add_side(_color, {1, 2, 13, 12});
    add_side(_color, {2, 3, 14, 13});
    add_side(_color, {0, 4, 15, 11});
    add_side(_color, {4, 5, 16, 15});

    add_vertex(Point(cor_p.x - xs*R/sqrt(8), y0, mid_p.z + zs*R)); // 17
    add_vertex(Point(mid_p.x + xs*R,         yd, mid_p.z + zs*R));
    add_vertex(Point(cor_p.x + xs*w,         yd, mid_p.z + zs*R));
    add_vertex(Point(mid_p.x + xs*R,         yd, mid_p.z));        // 20
    add_vertex(Point(mid_p.x + xs*w,         yd, mid_p.z));

    add_side(_color, {3, 6, 17, 14});
    add_side(_color, {5, 8, 19, 16});
    add_side(_color, {6, 7, 18, 17});
    add_side(_color, {7, 9, 20, 18});
    add_side(_color, {8, 10, 21, 19});

    this->normalize_vertexes();
}

LongSkirting::~LongSkirting() {}

void LongSkirting::_set_center(const Point& cor_p, const Point& mid_p, double w)
{
    if (cor_p.x > 0)
        _center.x = cor_p.x + w/2;
    else
        _center.x = cor_p.x - w/2;
    _center.y = cor_p.y;
    _center.z = (cor_p.z + mid_p.z)/2;
}




ShortSkirting::ShortSkirting(QRgb color, const Point& cor_p, const Point& mid_p,
             double hu, double hd, double w, double R)
{
    _color = color;

    int xs = sign_double(cor_p.x);  // x offset sign
    int zs = sign_double(cor_p.z);  // z offset sign
    double yu = cor_p.y + hu;

    // Top vertexes
    add_vertex(Point(cor_p.x + xs*w,            yu, cor_p.z + zs*w));          // 0
    add_vertex(Point(cor_p.x + xs*R/sqrt(2),    yu, cor_p.z + zs*R/sqrt(2)));
    add_vertex(Point(cor_p.x,                   yu, cor_p.z + zs*R));
    add_vertex(Point(cor_p.x,                   yu, cor_p.z + zs*w));          // 3
    add_vertex(Point(cor_p.x - xs*R*3/sqrt(2),  yu, cor_p.z - zs*R/sqrt(2)));
    add_vertex(Point(cor_p.x - xs*R*3/sqrt(2),  yu, cor_p.z + zs*w));          // 5
    add_vertex(Point(mid_p.x,                   yu, cor_p.z - zs*R/sqrt(2)));
    add_vertex(Point(mid_p.x,                   yu, cor_p.z + zs*w));          // 7

    add_side(_color, {0, 1, 2, 3});
    add_side(_color, {2, 4, 5, 3});
    add_side(_color, {4, 5, 7, 6});


    // Bottom vertexes
    double yd = cor_p.y - hd;
    double y0 = cor_p.y;
    add_vertex(Point(cor_p.x + xs*w,            yd, cor_p.z + zs*w));          // 8
    add_vertex(Point(cor_p.x + xs*R/sqrt(2),    yd, cor_p.z + zs*R/sqrt(2)));
    add_vertex(Point(cor_p.x,                   yd, cor_p.z + zs*R));
    add_vertex(Point(cor_p.x,                   yd, cor_p.z + zs*w));          // 11
    add_vertex(Point(cor_p.x - xs*R*3/sqrt(2),  y0, cor_p.z - zs*R/sqrt(8)));
    add_vertex(Point(cor_p.x - xs*R*3/sqrt(2),  yd, cor_p.z + zs*w));          // 13
    add_vertex(Point(mid_p.x,                   y0, cor_p.z - zs*R/sqrt(8)));
    add_vertex(Point(mid_p.x,                   yd, cor_p.z + zs*w));          // 14

    add_side(_color, {0, 1, 9, 8});
    add_side(_color, {1, 2, 10, 9});
    add_side(_color, {2, 4, 12, 10});
    add_side(_color, {0, 3, 11, 8});
    add_side(_color, {3, 5, 13, 11});
    add_side(_color, {4, 6, 14, 12});
    add_side(_color, {5, 7, 15, 13});

    this->normalize_vertexes();
}

ShortSkirting::~ShortSkirting() {}

void ShortSkirting::_set_center(const Point& cor_p, const Point& mid_p, double w)
{
    _center.x = (cor_p.x + mid_p.x)/2;
    _center.y = cor_p.y;
    if (cor_p.z > 0)
        _center.z = cor_p.z + w/2;
    else
        _center.z = cor_p.z - w/2;
}

