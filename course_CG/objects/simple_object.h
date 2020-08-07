#ifndef SIMPLE_OBJECT_H
#define SIMPLE_OBJECT_H

#include "scene_object.h"
#include "3d_prmitives/model.h"

class SimpleObject: public SceneObject
{
public:
    SimpleObject();
    virtual ~SimpleObject() = 0;

    virtual bool is_complex() const final {return false;}
};

class VisibleObject: public SimpleObject
{
public:
    VisibleObject();
    explicit VisibleObject(const VisibleObject& other);
    virtual ~VisibleObject() = 0;

    shared_ptr<Model> get_model();

    virtual bool is_drawable() const final {return true;}

protected:
    shared_ptr<Model> _model;
};

class InvisibleObject: public SimpleObject
{
public:
    InvisibleObject();
    virtual ~InvisibleObject() = 0;

    virtual bool is_drawable() const final {return false;}
};


#endif // SIMPLE_OBJECT_H
