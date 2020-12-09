#include "composite_object.h"

CompositeObject::CompositeObject(): _obj_arr() {}
CompositeObject::CompositeObject(const CompositeObject& other)
{
    for (auto obj: other._obj_arr)
        _obj_arr.push_back(obj);
}
CompositeObject::~CompositeObject() {}


void CompositeObject::add_object(SceneObject *obj)
{
    _obj_arr.push_back(shared_ptr<SceneObject>(obj));
}
void CompositeObject::add_object(shared_ptr<SceneObject> obj)
{
    _obj_arr.push_back(obj);
}
void CompositeObject::remove_object(iter_obj &rem_iter)
{
    _obj_arr.erase(rem_iter);
}
