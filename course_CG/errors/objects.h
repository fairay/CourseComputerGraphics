#ifndef OBJECTS_H
#define OBJECTS_H

#include "base_error.h"


namespace err
{
class ObjectError: public SceneError
{
public:
    ObjectError(const string file_, long line_n_);
    virtual ~ObjectError();
};


class NotDrawable: public ObjectError
{
public:
    NotDrawable(const string file_, long line_n_);
    virtual ~NotDrawable();
};
class NotTransable: public ObjectError
{
public:
    NotTransable(const string file_, long line_n_);
    virtual ~NotTransable();
};
class UndefindeVisiter: public ObjectError
{
public:
    UndefindeVisiter(const string file_, long line_n_);
    virtual ~UndefindeVisiter();
};
class UndefindeClone: public ObjectError
{
public:
    UndefindeClone(const string file_, long line_n_);
    virtual ~UndefindeClone();
};

class VisitorError: public ObjectError
{
public:
    VisitorError(const string file_, long line_n_);
    virtual ~VisitorError();
};

class VisualExpired: public VisitorError
{
public:
    VisualExpired(const string file_, long line_n_);
    virtual ~VisualExpired();
};
class TransExpired: public VisitorError
{
public:
    TransExpired(const string file_, long line_n_);
    virtual ~TransExpired();
};

} // namespace err

#endif // OBJECTS_H
