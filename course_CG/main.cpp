#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    cout << "Sizeof QRGB: " << sizeof (QRgb) << endl;
    return a.exec();
}
