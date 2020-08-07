#include "drawer.h"

inline QRgb i_color(QRgb a, double aPers)
{
    char* a_ptr = reinterpret_cast<char*>(&a);
    double bPers = 1 - aPers;
    a_ptr[0] = static_cast<char>(a_ptr[0] * aPers + 255 * bPers);
    a_ptr[1] = static_cast<char>(a_ptr[1] * aPers + 255 * bPers);
    a_ptr[2] = static_cast<char>(a_ptr[2] * aPers + 255 * bPers);
    return a;
}


QDrawer::QDrawer(weak_ptr<QImage> image)
{
    if (image.expired())
        throw err::ImageExpired(__FILE__, __LINE__);

    _img = image;
    QSize size = _img.lock()->size();
    w = size.width();
    h = size.height();
    _init_map();
}
QDrawer::QDrawer(const QDrawer& other)
{
    _img = other._img;
    w = other.w;
    h = other.h;

    _init_map();
}
QDrawer::~QDrawer()
{
    _free_map();
}

void QDrawer::fill_rgb(QRgb color)
{
    for (int y=0; y < h; y++)
    {
        for (int x=0; x < w; x++)
            _color_map[y][x] = color;
    }
}
void QDrawer::fill_z(double depth)
{
    for (int y=0; y < h; y++)
    {
        for (int x=0; x < w; x++)
            _z_map[y][x] = depth;
    }
}

void QDrawer::draw_point(const Point &p, QRgb color)
{
    int x = static_cast<int>(p.x);
    int y = static_cast<int>(p.y);
    if (p.z > _z_map[y][x])
    {
        _color_map[y][x] = color;
        _z_map[y][x] = p.z;
    }
}
void QDrawer::draw_point(const Point &p, QRgb color, double i)
{
    int x = static_cast<int>(p.x);
    int y = static_cast<int>(p.y);
    if (p.z > _z_map[y][x])
    {
        _color_map[y][x] = i_color(color, i);
        _z_map[y][x] = p.z;
    }
}

void QDrawer::transfer_to_qimage()
{
    if (_img.expired())
        throw err::ImageExpired(__FILE__, __LINE__);

    cout << "\n\nShowing image" << endl;
    QImage& i = *_img.lock();
    size_t row_size = static_cast<size_t>(w) * sizeof(QRgb);
    for (int y=0; y < h; y++)
        memcpy(i.scanLine(y), &_color_map[y][0], row_size);
}


void QDrawer::_init_map()
{
    _color_map = new QRgb*[h];
    for (int i=0; i<h; i++)
        _color_map[i] = new QRgb[w];

    _z_map = new double*[h];
    for (int i=0; i<h; i++)
    {
        _z_map[i] = new double[w];

    }

}
void QDrawer::_free_map()
{
    for (int i=0; i<h; i++)
        delete _color_map[i];
    delete _color_map;
}
