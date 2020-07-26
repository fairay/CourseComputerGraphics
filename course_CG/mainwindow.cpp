#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _qscene(new QGraphicsScene(-10, -10, 10, 10))
{
    ui->setupUi(this);
    _scene_size = ui->graphicsView->size();
    ui->graphicsView->setSceneRect(0, 0, _scene_size.width()-2, _scene_size.height()-2);
    ui->graphicsView->setScene(&(*_qscene));
    cout << _scene_size.width() << ", " << _scene_size.height() << endl;
    cout << _qscene->width() << ", " << _qscene->height() << endl;

    _img = QImage(_scene_size.width(), _scene_size.height(), QImage::Format_RGB32);
    _img.setPixelColor(1, 1, Qt::red);
    _img.setPixelColor(101, 100, Qt::red);
    _img.setPixelColor(102, 100, Qt::red);
    q_pmap = _qscene->addPixmap(_pmap.fromImage(_img));

    _img.setPixelColor(101, 100, Qt::blue);
    _img.setPixelColor(102, 100, Qt::blue);
    // _qscene->addPixmap(_pmap.fromImage(_img));
    q_pmap->setPixmap(_pmap.fromImage(_img));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::_fill_img(QColor color)
{
    for (int x=0; x < _scene_size.width(); x++)
        for (int y=0; y < _scene_size.height(); y++)
            _img.setPixelColor(x, y, color);

    q_pmap->setPixmap(_pmap.fromImage(_img));
    QApplication::processEvents();
}

void MainWindow::on_pushButton_clicked()
{
    time_t time = clock();
    size_t count = 0;
    while(clock() - time < 1000 * 1.0)
    {
        for (auto color : _color_arr)
            _fill_img(color);
        count += _color_arr.size();
    }
    cout << "FPS: " << count << endl;
}
