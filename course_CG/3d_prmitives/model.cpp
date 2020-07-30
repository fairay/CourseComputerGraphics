#include "model.h"

Model::Model() {}
Model::~Model() {}

Model::Model(const vector<Point>& arr)
{
    this->add_vertexes(arr);
}


void Model::add_vertexes(const vector<Point> &arr)
{
    for (Point p : arr)
        add_vertex(p);
}

void Model::add_vertex(const Point &p)
{
    shared_ptr<Vertex> new_v(new Vertex(p));
    v_arr.push_back(new_v);
}

void Model::add_side(QRgb color, vector<size_t> index_arr)
{
    vector<shared_ptr<Vertex>> vertex_arr;
    for (size_t i : index_arr)
    {
        if (i >= v_arr.size())
            throw err::VertexUndefinded(__FILE__, __LINE__);
        vertex_arr.push_back(v_arr[i]);
    }
    _add_side(color, vertex_arr);
}


void Model::_add_side(QRgb color, vector<shared_ptr<Vertex>> vertex_arr)
{
    shared_ptr<Polygon> new_p(new Polygon(color, vertex_arr));
    p_arr.push_back(new_p);
}
