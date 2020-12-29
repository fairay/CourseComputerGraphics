#ifndef BUILDER_ERRORS_H
#define BUILDER_ERRORS_H


#include "base_error.h"

namespace err
{
class BuilderError: public SceneError
{
public:
    BuilderError(const string file_, long line_n_);
    virtual ~BuilderError();
};



class FileOpenFail: public BuilderError
{
public:
    FileOpenFail(const string file_, long line_n_, const string name_);
    virtual ~FileOpenFail();
};

class FileNotOpen: public BuilderError
{
public:
    FileNotOpen(const string file_, long line_n_);
    virtual ~FileNotOpen();
};

class WrongBallR: public BuilderError
{
public:
    WrongBallR(const string file_, long line_n_);
    virtual ~WrongBallR();
};

class WrongBallCount: public BuilderError
{
public:
    WrongBallCount(const string file_, long line_n_);
    virtual ~WrongBallCount();
};

class WrongTableSize: public BuilderError
{
public:
    WrongTableSize(const string file_, long line_n_);
    virtual ~WrongTableSize();
};

class WrongBallPosition: public BuilderError
{
public:
    WrongBallPosition(const string file_, long line_n_);
    virtual ~WrongBallPosition();
};

} // err

#endif // BUILDER_ERRORS_H
