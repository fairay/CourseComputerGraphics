#include "draw.h"

using namespace manager;

DrawManager::DrawManager(weak_ptr<Scene> scene_ptr):
    IManager(scene_ptr) {}
DrawManager::~DrawManager() {}
void DrawManager::execute()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "DrawManager");

    shared_ptr<Scene> scene = _scene.lock();

    shared_ptr<Visualizer> visual(new Visualizer());
    visual->set_draw(scene->get_drawer());
    visual->set_camera(*scene->get_camera());
    visual->set_light(*scene->get_light());

    shared_ptr<ObjectVisitor> visitor(new DrawVisitor(visual));

    visual->clear();
    for (auto obj: *_scene.lock())
        obj->accept(*visitor);
    visual->show();
}
