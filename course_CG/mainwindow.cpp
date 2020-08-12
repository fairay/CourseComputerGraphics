#include "mainwindow.h"
#include "ui_mainwindow.h"

/// Функции для работы с RgbMap
RgbMap create_rgb_map(int w, int h)
{
    RgbMap mat = new QRgb*[h];
    for (int i=0; i<h; i++)
        mat[i] = new QRgb[w];
    return mat;
}
void free_rgb_map(RgbMap& mat, int h)
{
    for (int i=0; i<h; i++)
        delete mat[i];
    delete mat;
}
void fill_rgb_map(RgbMap& mat, int w, int h, QColor color)
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
    _scene(new Scene())
{
    ui->setupUi(this);
    _scene_size = ui->graphicsView->size();
    cout << "Image size: " << _scene_size.width() << "x" << _scene_size.height() << endl;

    // Cоздание матрицы изображения
    _rgb_map = create_rgb_map(_scene_size.width(), _scene_size.height());

    ui->graphicsView->setSceneRect(0, 0, _scene_size.width(), _scene_size.height());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(&(*_qscene));

    _img = shared_ptr<QImage>(new QImage(_scene_size.width(), _scene_size.height(), QImage::Format_RGB32));
    _test_init();

    command::InitDraw cmd(_img);
    _scene.execute(cmd);
    _paint();
}

MainWindow::~MainWindow()
{
    delete ui;
    free_rgb_map(_rgb_map, _scene_size.height());
}


/// Отображение сцены
void MainWindow::_paint()
{
    command::DrawScene cmd;
    _scene.execute(cmd);
    q_pmap->setPixmap(QPixmap::fromImage(*_img));
    QCoreApplication::processEvents();
}

/// Тестовый запуск
void MainWindow::_test_init()
{
    // Создание объекта, отображающего _img
    q_pmap = _qscene->addPixmap(QPixmap::fromImage(*_img));

    // Пример рисования с помощью setPixelColor (неоптимальный вариант закраски)
    _img->setPixelColor(1, 1, Qt::red);
    _img->setPixelColor(101, 100, Qt::white);
    _img->setPixelColor(102, 100, Qt::red);
    q_pmap->setPixmap(QPixmap::fromImage(*_img));
}

/// Перекраска сцены
void MainWindow::_fill_img(QColor color)
{
    int w = _scene_size.width();
    int h = _scene_size.height();

    // Заполнение матрицы цветов
    fill_rgb_map(_rgb_map, w, h, color);

    // Перенос матрицы цветов на _img
    size_t row_size = static_cast<size_t>(w) * sizeof(QRgb);
    for (int y=0; y < h; y++)
        memcpy(_img->scanLine(y), &_rgb_map[y][0], row_size);

    // Копирование _img на экран, обновление
    q_pmap->setPixmap(QPixmap::fromImage(*_img));
    QCoreApplication::processEvents();
}

/// Тест FPS
void MainWindow::on_pushButton_clicked()
{
    _paint();
    return;
    time_t time = clock();
    size_t count = 0;
    while(clock() - time < 1000)
    {
        // заполнение экрана очередным цветом
        _fill_img(_color_arr[count % _color_arr.size()]);
        count++;
    }
    cout << "FPS: " << count << endl;
    ui->fps_count->setNum(static_cast<int>(count));
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    cout << event->key() << endl;

    switch (event->key())
    {
    case Qt::Key_W:
        cout << "W\n\n";
        command::MoveCamera cmd(Vector(0, 0, -10));
        _scene.execute(cmd);
        _paint();
        break;
    //default:
    //    break;
    }
}
