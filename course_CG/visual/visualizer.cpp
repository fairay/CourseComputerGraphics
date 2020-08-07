#include "visualizer.h"

Visualizer::Visualizer() {}
Visualizer::Visualizer(shared_ptr<QDrawer>& drawer):
    _draw(drawer) {}
Visualizer::~Visualizer() {}

void Visualizer::set_draw(shared_ptr<QDrawer> &drawer) { _draw = drawer; }
void Visualizer::set_light(const LightSource &light) { _light = light; }
void Visualizer::set_camera(const Camera &camera) { _camera = camera; }

void Visualizer::draw_model(Model &m)
{
    for (auto p : m.v_arr)
    {
        Point pro = _proj_point(*p);
        _draw->draw_point(pro, m.p_arr[0]->color);
    }
}

void Visualizer::clear()
{
    _draw->fill_z(-10000);
    _draw->fill_rgb(Qt::gray);
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
        k = cam_pos.z / (cam_pos.z - res.z);

    res.x = cam_pos.x + (res.x - cam_pos.x)*k;
    res.y = cam_pos.y + (res.y - cam_pos.y)*k;
    return res;
}
