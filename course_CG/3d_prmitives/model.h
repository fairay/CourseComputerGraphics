#ifndef MODEL_H
#define MODEL_H

#include "polygon.h"

#define MESH_STEP 2
#define PI 3.14159265359

class Model
{
public:
    Model();
    Model(const vector<Point>& arr);
    ~Model();

    void add_vertex(const Point& p);
    void add_vertexes(const vector<Point>& arr);
    void add_side(QRgb color, vector<size_t> index_arr);

    void normalize_vertexes();
protected:
    vector<shared_ptr<Polygon>> p_arr;
    vector<shared_ptr<Vertex>> v_arr;
    Point _center;

    void _add_side(QRgb color, vector<shared_ptr<Vertex>> vertex_arr);
    void _print();
};


class BallModel: public Model
{
public:
    BallModel(QRgb color, double r, Point center = Point(0,0,0));
    ~BallModel();

private:
    QRgb _color;
    double _r;

    void _add_vertex_row(double h, size_t vertex_n);
    void _add_side(QRgb color, vector<shared_ptr<Vertex>> vertex_arr);
};

#endif // MODEL_H
