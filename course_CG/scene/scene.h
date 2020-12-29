#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>

#include "objects/scene_object.h"
#include "objects/camera.h"
#include "objects/light_source.h"
#include "objects/leg.h"
#include "objects/cue_ball.h"
#include "objects/plate.h"
#include "objects/rails.h"
#include "objects/table.h"

#include "visual/drawer.h"
#include "updater/updater.h"


using scene_iter = vector<shared_ptr<SceneObject>>::iterator;
using scene_citer = vector<shared_ptr<SceneObject>>::const_iterator;

using namespace std;

class Scene
{
public:
    Scene();
    ~Scene();

    size_t get_size();
    void clear_obj();

    scene_iter begin()      { return _arr.begin(); }
    scene_iter end()        { return _arr.end(); }
    scene_citer begin() const   { return _arr.cbegin(); }
    scene_citer end() const     { return _arr.cend(); }
    scene_citer cbegin()    { return _arr.cbegin(); }
    scene_citer cend()      { return _arr.cend(); }

    shared_ptr<Camera> get_camera();
    void set_camera(const Camera&);
    shared_ptr<LightSource> get_light();
    void set_light(const LightSource&);
    shared_ptr<QDrawer> get_drawer();
    void set_drawer(const QDrawer&);
    void set_drawer(shared_ptr<QDrawer>&);
    shared_ptr<Updater> get_updater();
    void set_updater(shared_ptr<Updater> &ptr);

    double get_dt();

    void add_object(SceneObject* obj);
    void add_object(shared_ptr<SceneObject> obj);
    void add_main_ball(const Point& pos_, double r_, QRgb color_=QColor(130, 0, 0).rgba());
    void add_ball(const Point& pos_, double r_, QRgb color_=QColor(235, 227, 171).rgba());
    void remove_object(scene_iter& iter);

private:
    double _cur_t = -1;
    vector<shared_ptr<SceneObject>> _arr;
    vector<shared_ptr<CueBall>> _ball_arr;
    shared_ptr<Camera> _cam;
    shared_ptr<LightSource> _light;
    shared_ptr<Updater> _upd;

    shared_ptr<QDrawer> _draw;

    void _test1_init();
    void _test2_init();
};

#endif // SCENE_H
