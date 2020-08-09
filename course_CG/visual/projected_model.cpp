#include "projected_model.h"

///
ProjEdge::ProjEdge(Point& p1, double i1,
                   Point& p2, double i2)
{
    if (p1.y < p2.y)
        swap(p1, p2);

    ymax = static_cast<int>(p1.y);
    x0 = p1.x;
    z0 = p1.z;
    i0 = i1;
    y0 = static_cast<int>(p1.y - p2.y);

    if (y0)
    {
        dx = (p1.x - p2.x) / y0;
        dz = (p1.z - p2.z) / y0;
        di = (i1 - i2) / y0;
    }
    else
    {
        dx = 0;
        dz = 0;
        di = 0;
    }

    this->reset();
}
ProjEdge::ProjEdge(const ProjEdge& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    i = other.i;

    x0 = other.x0;
    y0 = other.y0;
    z0 = other.z0;
    i0 = other.i0;

    dx = other.dx;
    dz = other.dz;
    di = other.di;
    ymax = other.ymax;
}
ProjEdge::~ProjEdge() {}

void ProjEdge::reset()
{
    x = x0;
    z = z0;
    i = i0;
    y = y0;
}
bool ProjEdge::step()
{
    x += dx;
    z += dz;
    y -= 1;
    i += di;
    return y <= 0;
}
void ProjEdge::print()
{
    printf("PE: [%7.3f, %7.3d, %7.3f] (y0:%d, ymax:%d)\n", x, y, z, y0, ymax);
}

bool ProjEdge::is_done() const
{
    return y <= 0;
}
bool ProjEdge::is_horizontal() const
{
    return y0 == 0;
}


///
ProjSide::ProjSide() {}
ProjSide::~ProjSide()
{
    edges.clear();
    active_edges.clear();
    waiting_edges.clear();
    cout << "ProjSide cleared" << endl;
}

void ProjSide::init()
{
    temp_y = edges[0].ymax;
    size_t i = 0;
    while (edges[i].ymax == temp_y)
        active_edges.push_back(edges[i++]);
    for (; i < edges.size(); i++)
        waiting_edges.push_back(edges[i]);
}
void ProjSide::add_edge(const ProjEdge &edge)
{
    if (edge.is_horizontal())
    {
        cout << "Horizonal, didn't add" << endl;
        return;
    }
    cout << "Add edge, ymax = " << edge.ymax << endl;
    edges.push_back(edge);

    for (size_t i=edges.size()-1; i>0; i--)
    {
        if (edges[i-1].ymax < edges[i].ymax)
            swap(edges[i-1], edges[i]);
        else if (edges[i-1].ymax == edges[i].ymax)
        {
            if (edges[i-1].x > edges[i].x)
                swap(edges[i-1], edges[i]);
            else if (edges[i-1].x >= edges[i].x &&
                     edges[i-1].dx > edges[i].dx)
                swap(edges[i-1], edges[i]);
            else
                break;
        }
        else
            break;
    }

    for (auto e : edges) {
        e.print();
    }

}
bool ProjSide::step()
{
    temp_y -= 1;
    for (auto i=active_edges.begin(); i!=active_edges.end(); i++)
    {
        if (i->step())
        {
            active_edges.erase(i);
            if (i==active_edges.end()) break;
        }
    }

    auto i = waiting_edges.begin();
    while (i!=waiting_edges.end() && i->ymax == temp_y)
    {
        active_edges.push_back(*i);
        waiting_edges.erase(i);
        if (i==waiting_edges.end()) break;
        i++;
    }
    return is_done();
}
bool ProjSide::is_done()
{
    cout << "LAE lenght:" << active_edges.size() << endl;
    return active_edges.size() == 0;
}
