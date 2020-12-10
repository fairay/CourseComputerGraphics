#include "update_mng.h"

using namespace manager;

InitUpdaterManager::InitUpdaterManager(weak_ptr<Scene> scene_ptr):
    IManager(scene_ptr) {}
InitUpdaterManager::~InitUpdaterManager() {}
void InitUpdaterManager::execute()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "Init Updater Manager");
    shared_ptr<Updater> upd = _scene.lock()->get_updater();

    shared_ptr<ObjectVisitor> visitor(new InitUpdVisitor(upd));
    for (auto obj: *_scene.lock())
        obj->accept(*visitor);
}


UpdateManager::UpdateManager(weak_ptr<Scene> scene_ptr):
    IManager(scene_ptr) {}
UpdateManager::~UpdateManager() {}
void UpdateManager::execute()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "Update Manager");
    shared_ptr<Updater> upd = _scene.lock()->get_updater();
    double dt = _scene.lock()->get_dt();

    upd->update(dt);
}

