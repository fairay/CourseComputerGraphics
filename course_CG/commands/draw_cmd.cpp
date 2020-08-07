#include "draw.h"

using namespace command;

DrawScene::DrawScene() {}
DrawScene::~DrawScene() {}

void DrawScene::execute(weak_ptr<Scene> scene)
{
    manager::DrawManager(scene).execute();
}
