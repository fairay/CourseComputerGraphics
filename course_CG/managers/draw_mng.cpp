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
    visual->clear();

    scene->get_camera()->get_pos().print();
    scene->get_camera()->get_dir().print();

    shared_ptr<ObjectVisitor> svisitor(new ShadowVisitor(visual));
    for (auto obj: *_scene.lock())
        obj->accept(*svisitor);

    shared_ptr<ObjectVisitor> dvisitor(new DrawVisitor(visual));
    for (auto obj: *_scene.lock())
        obj->accept(*dvisitor);

    visual->show();
}
