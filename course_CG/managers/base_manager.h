#ifndef BASE_MANAGER_H
#define BASE_MANAGER_H

#include "scene/scene.h"
#include "errors/managers.h"

#include <memory>

using namespace std;

class IManager
{
public:
    IManager(weak_ptr<Scene> scene_ptr);
    virtual ~IManager() = 0;

    virtual void execute() = 0;

protected:
    weak_ptr<Scene> _scene;
};



#endif // BASE_MANAGER_H
