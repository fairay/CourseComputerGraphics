#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "memory"
#include "math.h"
#include "algorithm"

#include "objects/camera.h"
#include "objects/light_source.h"
#include "3d_prmitives/ball_model.h"
#include "projected_model.h"
#include "drawer.h"

#define BG_LIGHT 0.3

using namespace std;
class Visualizer
{
public:
    Visualizer();
    Visualizer(shared_ptr<QDrawer>& drawer);
    ~Visualizer();

    void set_draw(const shared_ptr<QDrawer>& drawer);
    void set_camera(const Camera& camera);
    void set_light(const LightSource& light);

    void draw_model(Model& m);
    void draw_shadow(Model& m);

    void clear();
    void show();

private:
    shared_ptr<QDrawer> _draw;
    Camera _camera;
    LightSource _light;
    Vector _light_dir;

    Point _proj_point(const Point& p);
    Point _proj_point(const Point& p, const Point& v_pos, const Vector& v_dir);
    Point _reproj_point(const Point &p);
    Point _proj_light(const Point &p);

    double _light_point(const Vertex& v);
    void _proj_side(ProjSide& proj, const vector<shared_ptr<Vertex>>& arr,
                    const Point& v_pos, const Vector& v_dir);
};
#endif // VISUALIZER_H
