#include "init_draw.h"

using namespace command;

InitDraw::InitDraw(const weak_ptr<QImage>& ptr): _image(ptr) {}
InitDraw::~InitDraw() {}

void InitDraw::execute(weak_ptr<Scene> scene)
{
    shared_ptr<QDrawer> ptr(new QDrawer(_image));
    manager::InitDrawManager(scene, ptr).execute();
}
