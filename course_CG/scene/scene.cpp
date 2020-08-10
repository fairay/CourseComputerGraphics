#include "scene.h"

Scene::Scene()
{
    set_camera(Camera(Point(0, 0, 500)));
    set_light(LightSource(Point(0, 0, 1000), 1));
    add_object(new TableLeg(200, 200, 200));
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
