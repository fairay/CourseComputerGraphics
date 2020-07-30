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
    new_p->correct_n(_center);
    p_arr.push_back(new_p);
}
void Model::_print()
{
    cout << "----------------   Vertex   ----------------" << endl;
    for (auto v : v_arr)
        v->print();

    cout << "----------------   Polygon   ----------------" << endl;
    for (auto v : p_arr)
        v->print();
}


///
/// Ball model
///
BallModel::BallModel(QRgb color, double r, Point center)
{
    _color = color;
    _r = r;
    _center = center;

    size_t lvl_n = static_cast<size_t>(2*r / MESH_STEP);
    size_t poly_n = lvl_n*2;
    double lvl_step = 2*r / lvl_n;
    double h = -r;

    add_vertex(Point(0, h, 0));
    size_t v_count = 1;
    h += lvl_step;


    _add_vertex_row(h, poly_n);
    for (size_t i=0; i<poly_n; i++)
    {
        vector<size_t> i_arr = {0,
                                i+1,
                                (i+1) % poly_n + 1};
        add_side(color, i_arr);
    }
    h += lvl_step;
    v_count += poly_n;

    for (size_t lvl=2; lvl < lvl_n; lvl++)
    {
        _add_vertex_row(h, poly_n);
        for (size_t i=0; i<poly_n-1; i++)
        {
            vector<size_t> i_arr = {v_count+i - poly_n,
                                    v_count+i+1 - poly_n,
                                    v_count+i,
                                    v_count+i+1};
            add_side(color, i_arr);
        }
        h += lvl_step;
        v_count += poly_n;
    }
    cout << "It's starts with..." << endl;

    add_vertex(Point(0, r, 0));
    for (size_t i=0; i<poly_n; i++)
    {
        vector<size_t> i_arr = {v_count,
                                v_count-poly_n + (i),
                                v_count-poly_n + (i+1)%poly_n};
        add_side(color, i_arr);
    }

    cout << "Wow, I've build this" << endl;
    this->_print();
}
BallModel::~BallModel() {}

void BallModel::_add_vertex_row(double h, size_t vertex_n)
{
    double row_r = _r*_r - h*h;
    double angle_step = PI * 2 / vertex_n;
    double a = 0;

    for (size_t i=0; i < vertex_n; i++, a+= angle_step)
    {
        add_vertex(Point(row_r*cos(a), h, row_r*sin(a)));
    }
}

