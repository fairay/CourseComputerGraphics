#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
//    Vector v(-100, -200, -100);
//    v.normalize();
//    v.print();

//    Point p;
//    p.x = v.x;  p.y = v.y;  p.z = v.z;
//    p.print();

//    double beta = atan(p.x / p.z);
//    p.rotate_oy(Point(0,0,0), beta);
//    p.print();

//    double alpha = - atan(p.y/p.z);
//    if (p.z>0) alpha += PI;
//    p.rotate_ox(Point(0,0,0), alpha);
//    p.print();

    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
