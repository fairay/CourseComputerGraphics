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

class ImageExpired: public DrawerError
{
public:
    ImageExpired(const string file_, long line_n_);
    virtual ~ImageExpired();
};

class NoSceneCamera: public DrawerError
{
public:
    NoSceneCamera(const string file_, long line_n_);
    virtual ~NoSceneCamera();
};

} // err

#endif // VISUAL_H
