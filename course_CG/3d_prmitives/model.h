#ifndef MODEL_H
#define MODEL_H

#include "polygon.h"

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

    void _add_side(QRgb color, vector<shared_ptr<Vertex>> vertex_arr);
};

#endif // MODEL_H
