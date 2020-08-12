#ifndef TRANSFORM_COMMAND_H
#define TRANSFORM_COMMAND_H

#include "base_command.h"
#include "managers/tranfrorm.h"
#include "transform/trans_action.h"

namespace command
{

class Transform: public ICommand
{
public:
    Transform(const shared_ptr<Transformator>&);
    virtual ~Transform() = 0;

    virtual void execute(weak_ptr<Scene> scene) = 0;
protected:
    shared_ptr<Transformator> _trans;
};

class Move: public Transform
{
public:
    Move(const Vector& v);
    virtual ~Move() = 0;

    virtual void execute(weak_ptr<Scene> scene) = 0;
};
class MoveCamera: public Move
{
public:
    MoveCamera(const Vector& v);
    virtual ~MoveCamera();

    virtual void execute(weak_ptr<Scene> scene);
};
class MoveLight: public Move
{
public:
    MoveLight(const Vector& v);
    virtual ~MoveLight();

    virtual void execute(weak_ptr<Scene> scene);
};

class Rotate: public Transform
{
public:
    Rotate(const Point& c, const Vector& v);
    virtual ~Rotate() = 0;

    virtual void execute(weak_ptr<Scene> scene) = 0;
};
class RotateCamera: public Rotate
{
public:
    RotateCamera(const Vector& v);
    virtual ~RotateCamera();

    virtual void execute(weak_ptr<Scene> scene);
};
class RotateLight: public Rotate
{
public:
    RotateLight(const Point& c, const Vector& v);
    virtual ~RotateLight();

    virtual void execute(weak_ptr<Scene> scene);
};

} // command

#endif // TRANSFORM_COMMAND_H
