#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QWidget>

#include <memory>
#include <iostream>
#include <time.h>
#include "3d_prmitives/ball_model.h"
#include "3d_prmitives/box_model.h"
using namespace std;

typedef QRgb** RgbMap;

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
    // QPixmap _pmap;
    QGraphicsPixmapItem* q_pmap;
    QColor _draw_color = Qt::black;
    RgbMap _rgb_map;

    vector<QColor> _color_arr = { Qt::red, Qt::green, Qt::blue, Qt::white, Qt::magenta, Qt::yellow };
    void _fill_img(QColor color);
};

#endif // MAINWINDOW_H
