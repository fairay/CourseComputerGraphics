#ifndef INIT_DRAW_COMMAND_H
#define INIT_DRAW_COMMAND_H

#include "base_command.h"
#include "managers/init_draw.h"

namespace command
{

class InitDraw: public ICommand
{
public:
    InitDraw(const weak_ptr<QImage>&);
    virtual ~InitDraw();

    virtual void execute(weak_ptr<Scene> scene);
private:
    weak_ptr<QImage> _image;
};

} // command


#endif // INIT_DRAW_COMMAND_H
