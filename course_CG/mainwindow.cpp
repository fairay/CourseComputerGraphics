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

    command::BuildScene cmd3("config0.txt");
    _scene.execute(cmd3);
    command::InitUpd cmd2;
    _scene.execute(cmd2);

    _paint();


    setMouseTracking(true);
    this->centralWidget()->setMouseTracking(true);
    // ui->graphicsView->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    free_rgb_map(_rgb_map, _scene_size.height());
}

/// Обновление сцены
void MainWindow::_upd()
{
    command::Update cmd0;
    _scene.execute(cmd0);
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
void MainWindow::_main_cycle()
{
    time_t time = clock();
    time_t pre_time = time - 1;
    while(clock() - time < 1000*MAX_TIME)
    {
        _upd();
        _paint();

        time_t new_time = clock();
        ui->fps_count->setNum(static_cast<int>(1000.0 / (new_time - pre_time)));
        pre_time = new_time;
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->fps_count->setNum(static_cast<int>(0));
    ui->pushButton->setVisible(false); //setEnabled(false);
    _main_cycle();
    ui->pushButton->setVisible(true);
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    cout << event->key() << endl;

    using namespace command;
    shared_ptr<ICommand> ptr;
    switch (event->key())
    {
    case Qt::Key_U:
        _rotate_camera(3, 0, 0);
        break;
    case Qt::Key_J:
        _rotate_camera(-3, 0, 0);
        break;
    case Qt::Key_H:
        _rotate_camera(0, 3, 0);
        break;
    case Qt::Key_K:
        _rotate_camera(0, -3, 0);
        break;


    case Qt::Key_W:
        _move_camera(0, 0, -15);
        break;
    case Qt::Key_A:
        _move_camera(-15, 0, 0);
        break;
    case Qt::Key_S:
        _move_camera(0, 0, 15);
        break;
    case Qt::Key_D:
        _move_camera(15, 0, 0);
        break;


    //default:
    //    break;
    }
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    _graphics_click(event->x(), event->y());
}

void MainWindow::_graphics_click(int x, int y)
{
    static QGraphicsView* gr = ui->graphicsView;
    static int x_size = gr->x(), y_size = gr->y();
    x -= x_size;   y -= y_size + 16;
    if (x > 0 && x < gr->size().width() && y>0 && y<gr->size().height())
        cout << x << " " << y << endl;
    else
        return;

    x -= gr->size().width()/2;    y = -y + gr->size().height()/2;
    double power = ui->hit_power->value() / 100.0;

    using namespace command;
    shared_ptr<ICommand> ptr;
    ptr = shared_ptr<ICommand>(new MakeHit(Point(x, y, 0), power));
    _scene.execute(*ptr);
}


void MainWindow::mouseMoveEvent(QMouseEvent *eventMove)
{
    static int pre_x = eventMove->x();
    static int pre_y = eventMove->y();
    const double k = 0.1;
    if (eventMove->buttons() == Qt::RightButton)
    {
        _rotate_camera((pre_y - eventMove->y())*k,
                       (pre_x - eventMove->x())*k,
                       0);
    }
    pre_x = eventMove->x();
    pre_y = eventMove->y();
}


void MainWindow::_move_camera(double x, double y, double z)
{
    using namespace command;
    shared_ptr<ICommand> ptr;
    ptr = shared_ptr<ICommand>(new MoveCamera(Vector(x, y, z)));
    _scene.execute(*ptr);
    // this->_paint();
}
void MainWindow::_move_light(double x, double y, double z)
{
    using namespace command;
    shared_ptr<ICommand> ptr;
    ptr = shared_ptr<ICommand>(new MoveLight(Vector(x, y, z)));
    _scene.execute(*ptr);
    // this->_paint();
}
void MainWindow::_rotate_camera(double x, double y, double z)
{
    using namespace command;
    shared_ptr<ICommand> ptr;
    ptr = shared_ptr<ICommand>(new RotateCamera(Vector(x, y, z)));
    _scene.execute(*ptr);
    // this->_paint();
}
void MainWindow::_change_light_i(double i)
{
    using namespace command;
    shared_ptr<ICommand> ptr;
    ptr = shared_ptr<ICommand>(new SetLightI(i));
    _scene.execute(*ptr);
    // this->_paint();
}

void MainWindow::on_cam_move_f_clicked() { _move_camera(0, 0, -15); }
void MainWindow::on_cam_move_l_clicked() { _move_camera(-15, 0, 0); }
void MainWindow::on_cam_move_r_clicked() { _move_camera(15, 0, 0); }
void MainWindow::on_cam_move_b_clicked() { _move_camera(0, 0, 15); }
void MainWindow::on_cam_move_u_clicked() { _move_camera(0, 15, 0); }
void MainWindow::on_cam_move_d_clicked() { _move_camera(0, -15, 0); }

void MainWindow::on_cam_rot_u_clicked() { _rotate_camera(3, 0, 0); }
void MainWindow::on_cam_rot_l_clicked() { _rotate_camera(0, 3, 0); }
void MainWindow::on_cam_rot_d_clicked() { _rotate_camera(-3, 0, 0); }
void MainWindow::on_cam_rot_r_clicked() { _rotate_camera(0, -3, 0); }


void MainWindow::on_lig_move_f_clicked() { _move_light(0, 0, -100); }
void MainWindow::on_lig_move_b_clicked() { _move_light(0, 0, 100); }
void MainWindow::on_lig_move_l_clicked() { _move_light(-100, 0, 0); }
void MainWindow::on_lig_move_r_clicked() { _move_light(100, 0, 0); }
void MainWindow::on_lig_move_u_clicked() { _move_light(0, 100, 0); }
void MainWindow::on_lig_move_d_clicked() { _move_light(0, -100, 0); }

void MainWindow::on_lig_i_valueChanged(int value)
{
    _change_light_i(value);
}

void MainWindow::on_cam_info_clicked()
{

}

void MainWindow::on_lig_info_clicked()
{

}
