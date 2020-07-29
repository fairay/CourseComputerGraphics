#include "mainwindow.h"
#include "ui_mainwindow.h"


Rgb_matrix create_rgb_matrix(int w, int h)
{
    Rgb_matrix mat = new QRgb*[h];
    for (int i=0; i<h; i++)
        mat[i] = new QRgb[w];
    return mat;
}
void free_rgb_matrix(Rgb_matrix& mat, int h)
{
    for (int i=0; i<h; i++)
        delete mat[i];
    delete mat;
}
void fill_rgb_matrix(Rgb_matrix& mat, int w, int h, QColor color)
{
    QRgb code = color.rgba();
    for (int y=0; y < h; y++)
    {
        for (int x=0; x < w; x++)
            mat[y][x] = code;
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _qscene(new QGraphicsScene(-10, -10, 10, 10)),
    _rgb_map(create_rgb_matrix(_scene_size.width(), _scene_size.height()))
{
    ui->setupUi(this);

    _scene_size = ui->graphicsView->size();
    cout << _scene_size.width() << ", " << _scene_size.height() << endl;

    ui->graphicsView->setSceneRect(0, 0, _scene_size.width()-2, _scene_size.height()-2);
    ui->graphicsView->setScene(&(*_qscene));

    _img = QImage(_scene_size.width(), _scene_size.height(), QImage::Format_RGB32);
    q_pmap = _qscene->addPixmap(_pmap.fromImage(_img));

    _img.setPixelColor(1, 1, Qt::red);
    _img.setPixelColor(101, 100, Qt::red);
    _img.setPixelColor(102, 100, Qt::red);
    q_pmap->setPixmap(QPixmap::fromImage(_img));
}

MainWindow::~MainWindow()
{
    delete ui;
    free_rgb_matrix(_rgb_map, _scene_size.height());
}


void MainWindow::_fill_img(QColor color)
{
    int w = _scene_size.width();
    int h = _scene_size.height();

    fill_rgb_matrix(_rgb_map, w, h, color);

    size_t row_size = static_cast<size_t>(w) * sizeof(QRgb);
    for (int y=0; y < h; y++)
        memcpy(_img.scanLine(y), &_rgb_map[y][0], row_size);

    q_pmap->setPixmap(QPixmap::fromImage(_img));
    QCoreApplication::processEvents();
}

void MainWindow::on_pushButton_clicked()
{
    time_t time = clock();
    size_t count = 0;
    while(clock() - time < 1000)
    {
        _fill_img(_color_arr[count % _color_arr.size()]);
        count++;
    }
    cout << "FPS: " << count << endl;
    ui->fps_count->setNum(static_cast<int>(count));
}


