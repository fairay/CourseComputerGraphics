#include "update_cmd.h"

using namespace command;

InitUpd::InitUpd() {}
InitUpd::~InitUpd() {}

void InitUpd::execute(weak_ptr<Scene> scene)
{
     manager::InitUpdaterManager(scene).execute();
}


Update::Update() {}
Update::~Update() {}

void Update::execute(weak_ptr<Scene> scene)
{
     manager::UpdateManager(scene).execute();
}


MakeHit::MakeHit(const Point& click_p, double power):
    _click_p(click_p)
{
    _power = max<double>(power, 0);
    _power = min<double>(_power, 1);
}
MakeHit::~MakeHit() {}

void MakeHit::execute(weak_ptr<Scene> scene)
{
    manager::ShotManager(scene, _click_p, _power).execute();
}
