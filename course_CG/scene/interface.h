#ifndef INTERFACE_H
#define INTERFACE_H

#include "scene.h"
#include "commands/base_command.h"

class SceneInterface
{
public:
    SceneInterface(Scene* scene):
        _scene(scene) {}
    ~SceneInterface() = default;

    void execute(command::ICommand& cmd)
    { cmd.execute(weak_ptr<Scene>(_scene)); }
private:
    shared_ptr<Scene> _scene;
};

#endif // INTERFACE_H
