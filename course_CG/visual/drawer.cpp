#include "drawer.h"

inline QRgb i_color(QRgb a, double i)
{
    QColor c(a);
    int r, g, b;
    c.getRgb(&r, &g, &b);
    r *= i; g *= i; b *= i;
    c.setRgb(r, g, b);
    return c.rgba();
//    if (i>1)
//    {c.setRgb(0, 0, 0); cout << "OUT OF RANGE" << endl;}

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
void QDrawer::fill_z()
{
    for (int y=0; y < h; y++)
        for (int x=0; x < w; x++)
        {
            _z_map[y][x] = _min_depth;
            _shadow_map[y][x] = _min_depth;
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
void QDrawer::draw_point(const Point &p, QRgb color, double i, const Point &shad_p)
{
    int x = static_cast<int>(p.x) + w12;
    if (x < 0 || x >= w) {cout << "RET\n";return;}
    int y = -static_cast<int>(p.y) + h12;
    if (y < 0 || y >= h) {cout << "RET\n";return;}

    if (p.z > _z_map[y][x])
    {
        int sx = static_cast<int>(round(shad_p.x)) + w12;
        int sy = -static_cast<int>(round(shad_p.y)) + h12;
        if (sy >= 0 && sy < h && sx >= 0 && sx < w)
        {
            double dz = _shadow_map[sy][sx] - shad_p.z;
            if (dz > FULL_SHADOW_Z)
                i = BG_LIGHT;
            else if (dz > HALF_SHADOW_Z)
            {
                double k = (dz - HALF_SHADOW_Z)/(FULL_SHADOW_Z - HALF_SHADOW_Z);
                i = BG_LIGHT*k + i*(1-k);
            }
        }
        _color_map[y][x] = i_color(color, i);
        _z_map[y][x] = p.z;
    }
}
void QDrawer::draw_shadow(const Point& p)
{
    int x = static_cast<int>(p.x) + w12;
    if (x < 0 || x >= w) {return;}
    int y = -static_cast<int>(p.y) + h12;
    if (y < 0 || y >= h) {return;}

    if (p.z > _z_map[y][x])
        _shadow_map[y][x] = p.z;
}

void QDrawer::transfer_to_qimage()
{
    if (_img.expired())
        throw err::ImageExpired(__FILE__, __LINE__);

    // cout << "Showing image" << endl;
    QImage& i = *_img.lock();
    size_t row_size = static_cast<size_t>(w) * sizeof(QRgb);
    for (int y=0; y < h; y++)
        memcpy(i.scanLine(y), &_color_map[y][0], row_size);
}

void QDrawer::_init_map()
{
    _color_map = new QRgb*[h];
    _z_map = new double*[h];
    _shadow_map = new double*[h];

    for (int i=0; i<h; i++)
    {
        _color_map[i] = new QRgb[w];
        _z_map[i] = new double[w];
        _shadow_map[i] = new double[w];
    }
}
void QDrawer::_free_map()
{
    for (int i=0; i<h; i++)
    {
        delete _color_map[i];
        delete _z_map[i];
        delete _shadow_map[i];
    }

    delete _color_map;    
    delete _z_map;
    delete _shadow_map;
}

int QDrawer::get_min_x() const { return -w12; }
int QDrawer::get_min_y() const { return -h12; }
int QDrawer::get_max_x() const { return  w12; }
int QDrawer::get_max_y() const { return  h12; }
