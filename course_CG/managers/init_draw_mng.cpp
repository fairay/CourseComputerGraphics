#include "init_draw.h"

using namespace manager;

InitDrawManager::InitDrawManager(weak_ptr<Scene> scene_ptr, shared_ptr<QDrawer> draw):
    IManager(scene_ptr), _draw(draw) {}
InitDrawManager::~InitDrawManager() {}
void InitDrawManager::execute()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "InitDraw Manager");

    _scene.lock()->set_drawer(_draw);
}
