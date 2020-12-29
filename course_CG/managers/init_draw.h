#ifndef INIT_DRAW_H
#define INIT_DRAW_H

#include "base_manager.h"
#include "visual/visualizer.h"

namespace manager
{

class InitDrawManager: public IManager
{
public:
    InitDrawManager(weak_ptr<Scene> scene_ptr, shared_ptr<QDrawer> draw);
    virtual ~InitDrawManager();

    virtual void execute();
private:
    shared_ptr<QDrawer> _draw;
};

} // namespace manager


#endif // INIT_DRAW_H
