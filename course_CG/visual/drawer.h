#ifndef DRAWER_H
#define DRAWER_H

#include <QImage>
#include "memory"
#include <math.h>
#include "errors/visual.h"
#include "3d_prmitives/point.h"

using RgbMap = QRgb**;
using ZMap = double**;
using namespace std;

class QDrawer
{
public:
    QDrawer(weak_ptr<QImage> image);
    explicit QDrawer(const QDrawer& other);
    virtual ~QDrawer();

    void fill_rgb(QRgb color);
    void fill_z();
    void draw_point(const Point& p, QRgb color);
    void draw_point(const Point& p, QRgb color, double i, const Point& shad_p);
    void draw_shadow(const Point& p);
    void transfer_to_qimage();

    int get_min_x() const;
    int get_min_y() const;
    int get_max_x() const;
    int get_max_y() const;
private:
    weak_ptr<QImage> _img;
    RgbMap _color_map;
    ZMap _z_map;
    ZMap _shadow_map;
    int w, h;
    int w12, h12;
    const double _min_depth = -1e100;

    void _init_map();
    void _free_map();
};

#endif // DRAWER_H
