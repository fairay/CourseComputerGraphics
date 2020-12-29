#ifndef MANAGERS_ERROR_H
#define MANAGERS_ERROR_H

#include "base_error.h"

namespace err
{

class ManagerError: public SceneError
{
public:
    ManagerError(const string file_, long line_n_,
                 const string mng_);
    virtual ~ManagerError();
};

class ScenePtrExpired: public ManagerError
{
public:
    ScenePtrExpired(const string file_, long line_n_,
                    const string mng_);
    virtual ~ScenePtrExpired();
};

class AttributePtrExpired: public ManagerError
{
public:
    AttributePtrExpired(const string file_, long line_n_,
                        const string mng_);
    virtual ~AttributePtrExpired();
};

class IOutOfScene: public ManagerError
{
public:
    IOutOfScene(const string file_, long line_n_,
                const string mng_, size_t index);
    virtual ~IOutOfScene();
};

};

#endif // MANAGERS_ERROR_H
