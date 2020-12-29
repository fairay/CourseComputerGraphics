#ifndef DRAW_COMMAND_H
#define DRAW_COMMAND_H

#include "base_command.h"
#include "managers/draw.h"

namespace command
{

class DrawScene: public ICommand
{
public:
    DrawScene();
    virtual ~DrawScene();

    virtual void execute(weak_ptr<Scene> scene);
};

} // command

#endif // DRAW_COMMAND_H
