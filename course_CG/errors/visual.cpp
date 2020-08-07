#include "visual.h"

using namespace err;
DrawerError::DrawerError(const string file_, long line_n_):
    SceneError(file_, line_n_)
{
    type = "Drawer Error: ";
}
DrawerError::~DrawerError() = default;


ImageExpired::ImageExpired(const string file_, long line_n_):
    DrawerError(file_, line_n_)
{
    type += "Image Expired";
    add_info = "image pointer expired";
    fill_msg();
}
ImageExpired::~ImageExpired() = default;

NoSceneCamera::NoSceneCamera(const string file_, long line_n_):
    DrawerError(file_, line_n_)
{
    type += "NoSceneCamera";
    add_info = "scene has no camera";
    fill_msg();
}
NoSceneCamera::~NoSceneCamera() = default;
