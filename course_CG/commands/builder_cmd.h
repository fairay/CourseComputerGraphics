#ifndef BUILDER_CMD_H
#define BUILDER_CMD_H

#include "base_command.h"

namespace command
{

class BuildScene: public ICommand
{
public:
    BuildScene(string f_name);
    virtual ~BuildScene();

    virtual void execute(weak_ptr<Scene> scene);
private:
    string _f_name;
};
} // command

#endif // BUILDER_CMD_H
