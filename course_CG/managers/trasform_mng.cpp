#include "tranfrorm.h"

using namespace manager;

Transform::Transform(weak_ptr<Scene> scene_ptr, shared_ptr<Transformator> trans):
    IManager(scene_ptr), _trans(trans) {}
Transform::~Transform() {}
void Transform::execute() {}

void Transform::exe_camera()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "Transform Manager");

    _trans->rotate(_scene.lock()->get_camera()->get_dir());
    _trans->transform(*_scene.lock()->get_camera());
}
void Transform::exe_light()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "Transform Manager");

    _trans->transform(_scene.lock()->get_light()->get_pos());
}


ChangeI::ChangeI(weak_ptr<Scene> scene_ptr, double i):
    IManager(scene_ptr), _i(i) {}
ChangeI::~ChangeI() {}

void ChangeI::execute()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "Change light I Manager");

    _scene.lock()->get_light()->set_intensity(_i);
}
