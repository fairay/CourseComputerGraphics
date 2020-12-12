#ifndef UPDATE_MNG_H
#define UPDATE_MNG_H

#include "base_manager.h"
#include "updater/updater.h"
#include "objects/visitors/update_visitor.h"
#include <time.h>

namespace manager
{

class InitUpdaterManager: public IManager
{
public:
    InitUpdaterManager(weak_ptr<Scene> scene_ptr);
    virtual ~InitUpdaterManager();

    virtual void execute();
};

class UpdateManager: public IManager
{
public:
    UpdateManager(weak_ptr<Scene> scene_ptr);
    virtual ~UpdateManager();

    virtual void execute();
};

class ShotManager: public IManager
{
public:
    ShotManager(weak_ptr<Scene> scene_ptr, const Point& click_p, double power);
    virtual ~ShotManager();

    virtual void execute();
private:
    Point _click_p;
    double _power;
};

} // namespace manager



#endif // UPDATE_MNG_H
