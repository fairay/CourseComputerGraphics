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


#define CAM_COEF 500
#define LIGHT_COEF 0.15
#define TEMP_COEF 600

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

    Point proj_point(const Point &p);
    Point reproj_point(const Point &p);

    void clear();
    void show();

private:
    shared_ptr<QDrawer> _draw;
    Camera _camera;
    LightSource _light;
    Vector _light_dir;

    Point _proj_point(const Point& p);
    Point _proj_point(const Point& p, const Point& v_pos, const Vector& v_dir, double coef);
    Point _reproj_point(const Point &p);
    Point _proj_light(const Point &p);

    double _light_point(const Vertex& v);
    void _proj_side(ProjSide& proj, const vector<shared_ptr<Vertex>>& arr,
                    const Point& v_pos, const Vector& v_dir, double coef);
};
#endif // VISUALIZER_H
