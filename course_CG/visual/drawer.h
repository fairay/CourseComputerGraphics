#ifndef DRAWER_H
#define DRAWER_H

#include <QImage>
#include "memory"
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
    void fill_z(double depth);
    void draw_point(const Point& p, QRgb color);
    void draw_point(const Point& p, QRgb color, double i);
    void transfer_to_qimage();

private:
    weak_ptr<QImage> _img;
    RgbMap _color_map;
    ZMap _z_map;
    int w, h;

    void _init_map();
    void _free_map();
};

#endif // DRAWER_H