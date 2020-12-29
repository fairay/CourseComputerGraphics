#include "managers.h"

using namespace err;
ManagerError::ManagerError(const string file_, long line_n_,
                           const string mng_): SceneError(file_, line_n_)
{
    type = "Manager Error (" + mng_ + "): ";
}
ManagerError::~ManagerError() = default;


ScenePtrExpired::ScenePtrExpired(const string file_, long line_n_,
                                 const string mng_):
    ManagerError (file_, line_n_, mng_)
{
    type += "ScenePtrExpired";
    add_info = "Weak pointer of scene expired";
    fill_msg();
}
ScenePtrExpired::~ScenePtrExpired() = default;

AttributePtrExpired::AttributePtrExpired(const string file_, long line_n_,
                                         const string mng_):
    ManagerError (file_, line_n_, mng_)
{
    type += "AttributePtrExpired";
    add_info = "Weak pointer of manger attrbute expired";
    fill_msg();
}
AttributePtrExpired::~AttributePtrExpired() = default;

IOutOfScene::IOutOfScene(const string file_, long line_n_,
                         const string mng_, size_t index):
    ManagerError (file_, line_n_, mng_)
{
    type += "IOutOfScene";
    add_info = "Index out of range: " + to_string(index);
    fill_msg();
}
IOutOfScene::~IOutOfScene() = default;
