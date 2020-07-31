#include "visual.h"

using namespace err;
DrawerError::DrawerError(const string file_, long line_n_):
    SceneError(file_, line_n_)
{
    type = "Drawer Error: ";
}
DrawerError::~DrawerError() = default;


SceneExpired::SceneExpired(const string file_, long line_n_):
    DrawerError(file_, line_n_)
{
    type += "SceneExpired";
    add_info = "scene pointer expired";
    fill_msg();
}
SceneExpired::~SceneExpired() = default;

NoSceneCamera::NoSceneCamera(const string file_, long line_n_):
    DrawerError(file_, line_n_)
{
    type += "NoSceneCamera";
    add_info = "scene has no camera";
    fill_msg();
}
NoSceneCamera::~NoSceneCamera() = default;
