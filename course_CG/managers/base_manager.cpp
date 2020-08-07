#include "base_manager.h"

IManager::IManager(weak_ptr<Scene> scene_ptr):
    _scene(scene_ptr) {}
IManager::~IManager() {}
