#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include "errors/objects.h"
#include "memory"

class ObjectVisitor;

using namespace std;
class SceneObject
{
public:
    SceneObject();
    virtual ~SceneObject() = 0;

    virtual bool is_drawable() const;
    virtual bool is_observer() const;
    virtual bool is_complex() const;

    virtual void accept(ObjectVisitor&);
    virtual SceneObject* clone();
};


#endif // SCENE_OBJECT_H
