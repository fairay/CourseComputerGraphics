#ifndef BUILD_MNG_H
#define BUILD_MNG_H

#include "base_manager.h"
#include "errors/builder_errors.h"
#include <fstream>

namespace manager
{
class BuildManager: public IManager
{
public:
    BuildManager(weak_ptr<Scene> scene_ptr, string f_name);
    virtual ~BuildManager();

    virtual void execute();

private:
    string _f_name;
    ifstream _file;
};

} // namespace manager


#endif // BUILD_MNG_H
