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
