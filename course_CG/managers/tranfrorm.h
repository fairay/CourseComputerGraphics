#ifndef TRANFRORM_MANAGER_H
#define TRANFRORM_MANAGER_H


#include "base_manager.h"
#include "transform/transformator.h"

namespace manager
{

class Transform: public IManager
{
public:
    Transform(weak_ptr<Scene> scene_ptr, shared_ptr<Transformator> trans);
    virtual ~Transform();

    virtual void execute();

    void exe_camera();
    void exe_light();

private:
    shared_ptr<Transformator> _trans;
};

class ChangeI: public IManager
{
public:
    ChangeI(weak_ptr<Scene> scene_ptr, double i);
    virtual ~ChangeI();

    virtual void execute();
private:
    double _i;
};

} // namespace manager

#endif // TRANFRORM_MANAGER_H
