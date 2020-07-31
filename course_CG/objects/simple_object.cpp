#include "simple_object.h"

SimpleObject::SimpleObject() {}
SimpleObject::~SimpleObject() {}

VisibleObject::VisibleObject() {}
VisibleObject::VisibleObject(const VisibleObject& other)
{
    _model = other._model;
}
VisibleObject::~VisibleObject() {}

InvisibleObject::InvisibleObject() {}
InvisibleObject::~InvisibleObject() {}
