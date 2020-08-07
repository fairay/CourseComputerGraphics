#include "simple_object.h"

SimpleObject::SimpleObject() {}
SimpleObject::~SimpleObject() {}

VisibleObject::VisibleObject() {}
VisibleObject::VisibleObject(const VisibleObject& other)
{
    _model = other._model;
}
VisibleObject::~VisibleObject() {}
shared_ptr<Model> VisibleObject::get_model()
{
    return _model;
}

InvisibleObject::InvisibleObject() {}
InvisibleObject::~InvisibleObject() {}
