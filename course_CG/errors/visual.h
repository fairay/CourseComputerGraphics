#ifndef VISUAL_H
#define VISUAL_H

#include "base_error.h"

namespace err
{

class DrawerError: public SceneError
{
public:
    DrawerError(const string file_, long line_n_);
    virtual ~DrawerError();
};

class SceneExpired: public DrawerError
{
public:
    SceneExpired(const string file_, long line_n_);
    virtual ~SceneExpired();
};

class NoSceneCamera: public DrawerError
{
public:
    NoSceneCamera(const string file_, long line_n_);
    virtual ~NoSceneCamera();
};

} // err

#endif // VISUAL_H
