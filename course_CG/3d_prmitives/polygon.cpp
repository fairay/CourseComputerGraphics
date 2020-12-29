#include "polygon.h"

Polygon::Polygon(QRgb color_, vector<shared_ptr<Vertex>> vertex_arr,
                 const Point& inside_point)
{
    this->color = color_;
    if (vertex_arr.size() < 3)
        throw err::LackOfVertex(__FILE__, __LINE__-1);
    v_arr = vertex_arr;

    find_normal();
    correct_n(inside_point);
    for (auto v : v_arr)
        v->n += this->n;
}
Polygon::~Polygon() {}


void Polygon::find_normal()
{
    Vertex p1 = *v_arr[0];
    Vertex p2 = *v_arr[1];
    Vertex p3 = *v_arr[2];

    n.x = (p2.y - p1.y)*(p3.z - p1.z) - (p3.y - p1.y)*(p2.z - p1.z);
    n.y = (p2.z - p1.z)*(p3.x - p1.x) - (p3.z - p1.z)*(p2.x - p1.x);
    n.z = (p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y);

    n.normalize();
}

void Polygon::correct_n(const Point &inside_point)
{
    Vector out_v(inside_point, *v_arr[0]);
    if (n.scalar_mult(out_v) < 0)
        this->n.invert();
}

void Polygon::print()
{
    printf("\n\n Polygon -> [%lf, %lf, %lf]\n", n.x, n.y, n.z);
    for (auto p : v_arr)
    {
        printf("\t");
        p->print();
    }
}
