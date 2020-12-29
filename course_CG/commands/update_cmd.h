#ifndef UPDATE_CMD_H
#define UPDATE_CMD_H

#include "base_command.h"
#include "managers/update_mng.h"

namespace command
{

class InitUpd: public ICommand
{
public:
    InitUpd();
    virtual ~InitUpd();

    virtual void execute(weak_ptr<Scene> scene);
};

class Update: public ICommand
{
public:
    Update();
    virtual ~Update();

    virtual void execute(weak_ptr<Scene> scene);
};

class MakeHit: public ICommand
{
public:
    MakeHit(const Point& click_p, double power);
    virtual ~MakeHit();

    virtual void execute(weak_ptr<Scene> scene);

private:
    Point _click_p;
    double _power;
};

} // command


#endif // UPDATE_CMD_H
