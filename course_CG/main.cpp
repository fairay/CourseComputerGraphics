#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    std::vector<shared_ptr<int>> arr{};
    arr.push_back(shared_ptr<int>(new int));
    arr.push_back(shared_ptr<int>(new int));

    shared_ptr<int> t = arr[1];
    if (arr[0] == t)
        cout << "0" << endl;
    if (arr[1] == t)
        cout << "1" << endl;


    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
