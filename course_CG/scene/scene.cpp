#include "scene.h"

Scene::Scene()
{
    set_camera(Camera(Point(500, 800, 1000), Vector(-0.5, 0.2, 0)));
    set_light(LightSource(Point(0, 1200, 100), 500));

     _test1_init();
}
Scene::~Scene() {}

size_t Scene::get_size() { return _arr.size(); }

shared_ptr<Camera> Scene::get_camera()
{
    return _cam;
}
void Scene::set_camera(const Camera& obj)
{
    _cam = shared_ptr<Camera>(new Camera(obj));
}

shared_ptr<LightSource> Scene::get_light()
{
    return _light;
}
void Scene::set_light(const LightSource& obj)
{
    _light = shared_ptr<LightSource>(new LightSource(obj));
}

shared_ptr<QDrawer> Scene::get_drawer()
{
    return _draw;
}
void Scene::set_drawer(const QDrawer& obj)
{
    _draw = shared_ptr<QDrawer>(new QDrawer(obj));
}
void Scene::set_drawer(shared_ptr<QDrawer> &ptr)
{
    _draw = ptr;
}

void Scene::add_object(SceneObject* obj)
{
    _arr.push_back(shared_ptr<SceneObject>(obj));
}
void Scene::add_object(shared_ptr<SceneObject> obj)
{
    _arr.push_back(obj);
}
void Scene::remove_object(scene_iter &iter)
{
    _arr.erase(iter);
}


void Scene::_test1_init()
{
//    set_camera(Camera(Point(1557.147053, 1401.787040, -138.390842),
//                   Vector(-0.655,  -4.027,   0.000)));
    set_camera(Camera(Point(352.240427, 1223.275656, 743.714337),
                   Vector(-1.205,  -7.919,   0.000)));

    set_light(LightSource(Point(0, 2200, 1000), 1500));

    add_object(new TableLeg(-600, -1300, 750));
    add_object(new TableLeg(600, -1300, 750));
    add_object(new TableLeg(-600, 1300, 750));
    add_object(new TableLeg(600, 1300, 750));

    add_object(new Plate(765, 1530, 2800, true));
    add_object(new Plate(765, 1530, 2800, false));
    Point p1(1530/2, 865, 2800/2);
    Point p12(1530/2, 865, 0);
    Point p13(0, 865, 2800/2);
    Point p24(0, 865, -2800/2);
    Point p2(1530/2, 865, -2800/2);
    double r = 57;
    double R = r*1.4;
    add_object(new SideRail(p1, p12, R));
    add_object(new SideRail(p2, p12, R));
    add_object(new HeadRail(p1, p13, R));
    add_object(new HeadRail(p2, p24, R));
    p1.x = -p1.x; p12.x = -p12.x; p2.x = -p2.x;
    add_object(new SideRail(p1, p12, R));
    add_object(new SideRail(p2, p12, R));
    add_object(new HeadRail(p1, p13, R));
    add_object(new HeadRail(p2, p24, R));

    add_object(new CueBall(Point(0, 910, 0), 57));
    add_object(new CueBall(Point(120, 910, 0), 57));
    add_object(new CueBall(Point(240, 910, 0), 57));
    add_object(new CueBall(Point(360, 910, 0), 57));
}


void Scene::_test2_init()
{
//    set_camera(Camera(Point(-548.043032, 1050.678560, 1.048028),
//                  Vector(-0.243,  -1.554,   0.000)));
    set_camera(Camera(Point(1557.147053, 1401.787040, -138.390842),
                   Vector(-0.655,  -4.027,   0.000)));

    set_light(LightSource(Point(0, 2200, 1000), 1500));

    add_object(new TableLeg(-600, -1300, 750));
    add_object(new TableLeg(600, -1300, 750));
    add_object(new TableLeg(-600, 1300, 750));
    add_object(new TableLeg(600, 1300, 750));

    add_object(new Plate(765, 1530, 2800, true));
    Point p1(1530/2, 865, 1400);
    Point p2(1530/2, 865, 0);
    add_object(new SideRail(p1, p2, 100));

    add_object(new CueBall(Point(0, 910, 0), 57));
    add_object(new CueBall(Point(120, 910, 0), 57));
    add_object(new CueBall(Point(240, 910, 0), 57));
    add_object(new CueBall(Point(360, 910, 0), 57));

    add_object(new CueBall(Point(0, 910, 120), 57));
    add_object(new CueBall(Point(120, 910, 120), 57));
    add_object(new CueBall(Point(240, 910, 120), 57));
    add_object(new CueBall(Point(360, 910, 120), 57));
}
