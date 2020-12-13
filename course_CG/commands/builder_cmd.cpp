#include "builder_cmd.h"
#include "managers/build_mng.h"

using namespace command;

BuildScene::BuildScene(string f_name): _f_name(f_name) {}
BuildScene::~BuildScene() {}

void BuildScene::execute(weak_ptr<Scene> scene)
{
     manager::BuildManager(scene, _f_name).execute();
}
