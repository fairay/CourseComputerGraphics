#include "drawer.h"

inline QRgb i_color(QRgb a, double i)
{
    QColor c(a);
    int r, g, b;
    c.getRgb(&r, &g, &b);
    r *= i; g *= i; b *= i;
    // printf("(%4.2f, %d, %d, %d)\t", i, r, g, b);
    c.setRgb(r, g, b);
    return c.rgba();
//    char* a_ptr = reinterpret_cast<char*>(&a);
//    a_ptr[1] = static_cast<char>(a_ptr[1] * i);
//    a_ptr[2] = static_cast<char>(a_ptr[2] * i);
//    a_ptr[3] = static_cast<char>(a_ptr[3] * i);
//    return a;
}


QDrawer::QDrawer(weak_ptr<QImage> image)
{
    if (image.expired())
        throw err::ImageExpired(__FILE__, __LINE__);

    _img = image;
    QSize size = _img.lock()->size();
    w = size.width();       w12 = w/2;
    h = size.height();      h12 = h/2;
    _init_map();
}
QDrawer::QDrawer(const QDrawer& other)
{
    _img = other._img;
    w = other.w;
    h = other.h;
    w12 = other.w12;
    h12 = other.h12;

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
    int x = static_cast<int>(p.x) + w12;
    if (x < 0 || x >= w) return;
    int y = -static_cast<int>(p.y) + h12;
    if (y < 0 || y >= h) return;

    if (p.z > _z_map[y][x])
    {
        _color_map[y][x] = color;
        _z_map[y][x] = p.z;
    }
}
void QDrawer::draw_point(const Point &p, QRgb color, double i)
{
    int x = static_cast<int>(p.x) + w12;
    if (x < 0 || x >= w) return;
    int y = -static_cast<int>(p.y) + h12;
    if (y < 0 || y >= h) return;

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
        _z_map[i] = new double[w];

}
void QDrawer::_free_map()
{
    for (int i=0; i<h; i++)
        delete _color_map[i];
    for (int i=0; i<h; i++)
        delete _z_map[i];

    delete _color_map;    
    delete _z_map;
}
