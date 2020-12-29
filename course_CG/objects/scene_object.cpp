#include "scene_object.h"

SceneObject::SceneObject() {}

SceneObject::~SceneObject() {}

bool SceneObject::is_drawable() const
{
    return false;
}
bool SceneObject::is_observer() const
{
    return false;
}
bool SceneObject::is_complex() const
{
    return false;
}

void SceneObject::accept(ObjectVisitor&)
{
    throw err::UndefindeVisiter(__FILE__, __LINE__);
}

SceneObject* SceneObject::clone()
{
    throw err::UndefindeClone(__FILE__, __LINE__);
}
