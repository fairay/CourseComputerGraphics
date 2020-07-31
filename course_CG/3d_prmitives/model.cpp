#include "model.h"

Model::Model() {}
Model::~Model() {}

Model::Model(const vector<Point>& arr)
{
    this->add_vertexes(arr);
}
Model::Model(const Model& other)
{
    _center = other._center;
    for (auto v : other.v_arr)
        this->add_vertex(*v);

    for (auto p : other.p_arr)
    {
        vector<shared_ptr<Vertex>> vertex_arr;
        for (auto v_other : p->v_arr)
            for (auto v_this : this->v_arr)
                if (*v_other == *v_this)
                    vertex_arr.push_back(v_this);
        this->_add_side(p->color, vertex_arr);
    }
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

void Model::add_side(QRgb color, std::initializer_list<size_t> arr)
{
    vector<shared_ptr<Vertex>> vertex_arr;
    for (size_t i : arr)
    {
        if (i >= v_arr.size())
            throw err::VertexUndefinded(__FILE__, __LINE__);
        vertex_arr.push_back(v_arr[i]);
    }
    _add_side(color, vertex_arr);
}

void Model::normalize_vertexes()
{
    for (auto v : v_arr)
        v->normalize();
}


void Model::_add_side(QRgb color, vector<shared_ptr<Vertex>> vertex_arr)
{
    shared_ptr<Polygon> new_p(new Polygon(color, vertex_arr, _center));
    p_arr.push_back(new_p);
}
void Model::_print()
{
    cout << "----------------   Vertex ("<<v_arr.size()<<")  ----------------" << endl;
    for (auto v : v_arr)
        v->print();

    cout << endl << "----------------   Polygon ("<<p_arr.size()<<")  ----------------" << endl;
    for (auto v : p_arr)
        v->print();
}
