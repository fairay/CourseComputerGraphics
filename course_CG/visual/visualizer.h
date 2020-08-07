#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "objects/camera.h"
#include "objects/light_source.h"
#include "drawer.h"
#include "memory"
#include "math.h"

using namespace std;
class Visualizer
{
public:
    Visualizer();
    Visualizer(shared_ptr<QDrawer>& drawer);
    ~Visualizer();

    void set_draw(shared_ptr<QDrawer>& drawer);
    void set_camera(const Camera& camera);
    void set_light(const LightSource& light);

    void draw_model(Model& m);

    void clear();
    void show();

private:
    shared_ptr<QDrawer> _draw;
    Camera _camera;
    LightSource _light;

    Point _proj_point(const Point& p);

};
#endif // VISUALIZER_H
