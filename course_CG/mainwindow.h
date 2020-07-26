#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include <memory>
#include <iostream>
#include <time.h>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<QGraphicsScene> _qscene;

    QSize _scene_size;
    QImage _img;
    QPixmap _pmap;
    QGraphicsPixmapItem* q_pmap;

    vector<QColor> _color_arr = { Qt::red, Qt::green, Qt::blue };
    void _fill_img(QColor color);
};

#endif // MAINWINDOW_H
