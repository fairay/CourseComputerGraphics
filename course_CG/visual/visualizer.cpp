#include "visualizer.h"

Visualizer::Visualizer() {}
Visualizer::Visualizer(shared_ptr<QDrawer>& drawer):
    _draw(drawer) {}
Visualizer::~Visualizer() {}

void Visualizer::set_draw(const shared_ptr<QDrawer> &drawer) { _draw = drawer; }
void Visualizer::set_light(const LightSource &light) { _light = light; }
void Visualizer::set_camera(const Camera &camera) { _camera = camera; }

void Visualizer::draw_model(Model &m)
{
    for (auto p : m.v_arr)
    {
        Point pro = _proj_point(*p);
        _draw->draw_point(pro, m.p_arr[0]->color);
    }

    for (auto poly : m.p_arr)
    {
        cout << "\n\n-----" << endl;
        poly->print();
        ProjSide proj;
        _proj_side(proj, poly->v_arr);
        QRgb color = poly->color;

        cout << "Let's draw!" << endl;
        proj.init();
        while (!proj.is_done())
        {
            cout << "Draw row: " << proj.temp_y << endl;
            int x = static_cast<int>(proj.active_edges[0].x);
            double z = proj.active_edges[0].z;
            Point p(x, proj.temp_y, z);

            double i = proj.active_edges[0].i;
            double di = (i-proj.active_edges[1].i) / (x-proj.active_edges[1].x);
            double dz = (z-proj.active_edges[1].z) / (x-proj.active_edges[1].x);
            for (; p.x < proj.active_edges[1].x; p.x++)
            {
                _draw->draw_point(p, color, i);
                p.z += dz;
                i += di;
            }
            proj.step();
        }
    }

}

void Visualizer::clear()
{
    _draw->fill_z(-10000);
    _draw->fill_rgb(QColor(Qt::gray).rgba());
}

void Visualizer::show()
{
    _draw->transfer_to_qimage();
}


Point Visualizer::_proj_point(const Point& p)
{
    Point res = p;
    Point cam_pos = _camera.get_pos();

    res.rotate(cam_pos, _camera.get_dir());

    double k;

    if (fabs(cam_pos.z - res.z) < 1e-5)
        k = 1e20;
    else
        k = 100 / (cam_pos.z - res.z);
        //k = cam_pos.z / (cam_pos.z - res.z);

    res.x = cam_pos.x + (res.x - cam_pos.x)*k;
    res.y = cam_pos.y + (res.y - cam_pos.y)*k;
    res.print();
    return res;
}

void Visualizer::_proj_side(ProjSide& proj, const vector<shared_ptr<Vertex>>& arr)
{
    size_t p_n = arr.size();

    for (size_t i=0; i < p_n; i++)
    {
        Point p1 = _proj_point(*arr[i]);
        Point p2 = _proj_point(*arr[(i+1)%p_n]);
        double i1 = _light_point(*arr[i]);
        double i2 = _light_point(*arr[(i+1)%p_n]);
        proj.add_edge(ProjEdge(p1, i1, p2, i2));
    }
}

double Visualizer::_light_point(const Vertex &v)
{
    Vector dir(v, _light.get_pos());
    double i = dir.scalar_mult(v.n) / dir.length();
    i *= _light.get_intensity() * LIGHT_REFLECT;
    i = max(0.05, i);
    cout << "I = " << i << endl;
    return i;
}
