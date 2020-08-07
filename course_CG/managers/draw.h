#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

#include "base_manager.h"
#include "visual/visualizer.h"
#include "objects/visitors/draw.h"

namespace manager
{

class DrawManager: public IManager
{
public:
    DrawManager(weak_ptr<Scene> scene_ptr);
    virtual ~DrawManager();

    virtual void execute();
};

} // namespace manager

#endif // DRAW_MANAGER_H
