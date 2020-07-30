#ifndef POLYGON_H
#define POLYGON_H

#include "vertex.h"
#include "vector.h"
#include "errors/primitives_error.h"

#include <QColor>
#include <vector>
#include <memory>

using namespace std;

class Polygon
{
public:
    Vector n;
    QRgb color;
    vector<shared_ptr<Vertex>> v_arr;

    Polygon() = delete;
    Polygon(QRgb color, vector<shared_ptr<Vertex>> vertex_arr);
    ~Polygon();

    void correct_n(const Point& inside_point);

    void print();

private:
    void find_normal();
};

#endif // POLYGON_H
