#ifndef MODEL_H
#define MODEL_H

#include "polygon.h"
#include "vertex.h"

class Model
{
public:
    Model();
    Model(const vector<Point>& arr);
    explicit Model(const Model& other);
    virtual ~Model();

    void add_vertex(const Point& p);
    void add_vertexes(const vector<Point>& arr);
    void add_side(QRgb color, vector<size_t> index_arr);
    void add_side(QRgb color, std::initializer_list<size_t> arr);

    void normalize_vertexes();

protected:
    vector<shared_ptr<Polygon>> p_arr;
    vector<shared_ptr<Vertex>> v_arr;
    Point _center;

    void _add_side(QRgb color, vector<shared_ptr<Vertex>> vertex_arr);
    void _print();
};




#endif // MODEL_H
