#include "visualizer.h"

Visualizer::Visualizer() {}
Visualizer::Visualizer(shared_ptr<QDrawer>& drawer):
    _draw(drawer) {}
Visualizer::~Visualizer() {}

void Visualizer::set_draw(const shared_ptr<QDrawer> &drawer) { _draw = drawer; }
void Visualizer::set_light(const LightSource &light)
{
    _light = light;

    Point p = light.get_pos();
    Vector v(p.x, p.y, p.z);
    v.normalize();
    p.x = v.x;  p.y = v.y;  p.z = v.z;

    double beta = atan(p.x / p.z);
    p.rotate_oy(Point(0,0,0), beta);
    double alpha = - atan(p.y/p.z);
    if (p.z<0) alpha += PI;

    _light_dir = Vector(alpha, beta, 0);
    cout << "Light dir ";
    _light_dir.print();
}
void Visualizer::set_camera(const Camera &camera) { _camera = camera; }

void Visualizer::draw_model(Model &m)
{
//    for (auto p : m.v_arr)
//    {
//        Point pro1 = _proj_light(*p);
//        p->print();
//        Point pro2 = _proj_point(*p);
//        pro2 = _reproj_point(pro2);
//        pro2.print();
//        cout << endl;
//    }
//    return;

    const int min_x = _draw->get_min_x();
    const int min_y = _draw->get_min_y();
    const int max_x = _draw->get_max_x();
    const int max_y = _draw->get_max_y();

    for (auto poly : m.p_arr)
    {
        ProjSide proj;
        try
        {
            _proj_side(proj, poly->v_arr, _camera.get_pos(), _camera.get_dir());
        }
        catch (int)
        {
            cout << "Undrawable side" << endl;
            continue;
        }

        if (proj.is_empty())
            continue;

        QRgb color = poly->color;
        proj.init();

        while (!proj.is_done() && proj.temp_y>max_y)
            proj.step();

        while (!proj.is_done() && proj.temp_y>min_y)
        {
            double x = proj.active_edges[0].x; // int x = static_cast<int>(...);
            double z = proj.active_edges[0].z;
            double i = proj.active_edges[0].i;
            Point p(x, proj.temp_y, z);

            if (proj.active_edges[1].x - x < 1)
            {
                proj.step();
                continue;
            }
            double dx = x-proj.active_edges[1].x;
            double di = (i-proj.active_edges[1].i) / dx;
            double dz = (z-proj.active_edges[1].z) / dx;

            Point l_p = _proj_light(_reproj_point(p));
            Point l_end = _proj_light(_reproj_point(Point(proj.active_edges[1].x, proj.temp_y, proj.active_edges[1].z)));
            double l_x = -(l_end.x - l_p.x) / dx,
                   l_y = -(l_end.y - l_p.y) / dx,
                   l_z = -(l_end.z - l_p.z) / dx;

            if (p.x < min_x)
            {
                double inc = min_x-p.x;
                p.z += dz * inc;
                i += di * inc;

                l_p.x += l_x*inc; l_p.y += l_y*inc; l_p.z += l_z*inc;

                p.x = min_x;
            }

            double to_x = min(proj.active_edges[1].x, static_cast<double>(max_x));
            for (; p.x < to_x; p.x++) // for (; p.x < to_x && i>BG_LIGHT; p.x++)
            {
//                shad_p = _reproj_point(p);
//                shad_p = _proj_light(shad_p);
                _draw->draw_point(p, color, i, l_p);
                p.z += dz;
                i += di;

                l_p.x += l_x; l_p.y += l_y; l_p.z += l_z;
            }

            proj.step();
        }
    }
}

void Visualizer::draw_shadow(Model& m)
{
    const int min_x = _draw->get_min_x();
    const int min_y = _draw->get_min_y();
    const int max_x = _draw->get_max_x();
    const int max_y = _draw->get_max_y();

    for (auto poly : m.p_arr)
    {
        ProjSide proj;
        try
        {
            _proj_side(proj, poly->v_arr, _light.get_pos(), _light_dir);
        }
        catch (int)
        {
            continue;
        }

        if (proj.is_empty())
            continue;

        proj.init();
        while (!proj.is_done() && proj.temp_y>max_y)
            proj.step();

        while (!proj.is_done() && proj.temp_y>min_y)
        {
            double x = proj.active_edges[0].x;
            double z = proj.active_edges[0].z;
            Point p(x, proj.temp_y, z);

            if (proj.active_edges[1].x - x < 1)
            {
                proj.step();
                continue;
            }
            double dz = (z-proj.active_edges[1].z) / (x-proj.active_edges[1].x);

            if (p.x < min_x)
            {
                p.z += dz * (min_x-p.x);
                p.x = min_x;
            }


            double to_x = min(proj.active_edges[1].x, static_cast<double>(max_x));
            for (; p.x < to_x; p.x++) // for (; p.x < to_x && i>BG_LIGHT; p.x++)
            {
                _draw->draw_shadow(p);
                p.z += dz;
            }

            proj.step();
        }
    }
}


void Visualizer::clear()
{
    _draw->fill_z();
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
    if (cam_pos.z - res.z <= 0)
        throw 2;
    else
        k = 500 / (cam_pos.z - res.z);

    res.x = (res.x - cam_pos.x)*k;
    res.y = (res.y - cam_pos.y)*k;
    return res;
}
Point Visualizer::_proj_point(const Point& p, const Point& v_pos, const Vector& v_dir)
{
    Point res = p;
    res.rotate(v_pos, v_dir);

    double k;
    if (v_pos.z - res.z <= 0)
        throw 2;
    else
        k = 500 / (v_pos.z - res.z);

    res.x = (res.x - v_pos.x)*k;
    res.y = (res.y - v_pos.y)*k;
    return res;
}
Point Visualizer::_reproj_point(const Point &p)
{
    Point res = p;
    Point cam_pos = _camera.get_pos();
    Vector cam_dir = _camera.get_dir();
    // cam_dir.invert();

    double k = 500 / (cam_pos.z - res.z);
    res.x = cam_pos.x + res.x / k;
    res.y = cam_pos.y + res.y / k;

    res.rerotate(cam_pos, cam_dir);
    return res;
}
Point Visualizer::_proj_light(const Point &p)
{
    Point res = p;
    Point light_pos = _light.get_pos();

    res.rotate(light_pos, _light_dir);

    double k;
    if (light_pos.z - res.z <= 0)
        k = 1e10;
    else
        k = 500 / (light_pos.z - res.z);

    res.x = (res.x - light_pos.x)*k;
    res.y = (res.y - light_pos.y)*k;
    return res;
}

void Visualizer::_proj_side(ProjSide& proj, const vector<shared_ptr<Vertex>>& arr,
                            const Point &v_pos, const Vector &v_dir)
{
    size_t p_n = arr.size();
    Point p_next, p_pre = _proj_point(*arr[0], v_pos, v_dir);
    double i_next, i_pre = _light_point(*arr[0]);

    for (size_t i=0; i < p_n; i++)
    {
        p_next = _proj_point(*arr[(i+1)%p_n], v_pos, v_dir);
        i_next = _light_point(*arr[(i+1)%p_n]);
        proj.add_edge(ProjEdge(p_pre, i_pre, p_next, i_next));
        p_pre = p_next;
        i_pre = i_next;
    }
}

double Visualizer::_light_point(const Vertex &v)
{
    Vector dir(v, _light.get_pos());
    double i = dir.scalar_mult(v.n) / pow(dir.length(), 2.0);
    i *= _light.get_intensity() * LIGHT_REFLECT;
    i = max(0.0, i); i = min(1.0, i);
    i = BG_LIGHT + i*(1-BG_LIGHT);
    return i;
}
