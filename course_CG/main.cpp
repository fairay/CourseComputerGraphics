#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QColor c(Qt::red);
    try {
        BallModel b_model(c.rgba(), 4);
    } catch (std::exception &error) {
        cout << error.what() << endl;
    }

    return a.exec();
}
