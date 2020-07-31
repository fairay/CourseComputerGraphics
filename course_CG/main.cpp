#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QColor c(Qt::red);
    try {
        //BallModel b_model(c.rgba(), 3, Point(100, 200, 300));
        BoxModel b_model(c.rgba(), Point(-1, -1, -1), Point(2, 2, 2));
    } catch (std::exception &error) {
        cout << error.what() << endl;
    }

    return a.exec();
}
