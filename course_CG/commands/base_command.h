#ifndef BASE_COMMAND_H
#define BASE_COMMAND_H

#include "scene/scene.h"
#include "managers/base_manager.h"

namespace command
{

class ICommand
{
public:
    ICommand();
    virtual ~ICommand() = 0;

    virtual void execute(weak_ptr<Scene> scene) = 0;
};

} // command

#endif // BASE_COMMAND_H
