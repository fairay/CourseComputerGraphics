#ifndef DRAWER_H
#define DRAWER_H

#include <QImage>
#include "memory"
#include "errors/visual.h"

using RgbMap = QRgb**;
using namespace std;
class QDrawer
{
public:
    QDrawer(shared_ptr<QImage> scene);
    virtual ~QDrawer();

    void fill(QRgb color);
    void draw_point(double x, double y, QRgb color);
    void draw_point(double x, double y, QRgb color, double i);
    void transfer_to_qimage();

private:
    weak_ptr<QImage> _img;
};

#endif // DRAWER_H
