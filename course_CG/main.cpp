#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    Point p(0, 2200, 0);
    Vector v(p.x, p.y, p.z);
    v.normalize();
    p.x = v.x;  p.y = v.y;  p.z = v.z;

    double alpha=0, beta=0;
    if (abs(p.z) > 1e-4)
        beta = atan(p.x / p.z);
    else
        beta = copysign(PI/2, p.x);
    p.rotate_oy(Point(0,0,0), beta);

    if (abs(p.z) > 1e-4)
        alpha = -atan(p.y/p.z);
    else
        alpha = -copysign(PI/2, p.y);
    if (p.z < -1e-4) alpha += PI;
    p.rotate_ox(Point(0,0,0), alpha);

    Vector _light_dir = Vector(alpha, beta, 0);
    _light_dir.print();

    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
