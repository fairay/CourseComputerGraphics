#ifndef PRIMITIVES_ERROR_H
#define PRIMITIVES_ERROR_H

#include "base_error.h"


namespace err
{
class PrimitivesError: public SceneError
{
public:
    PrimitivesError(const string file_, long line_n_);
    virtual ~PrimitivesError();
};


class LackOfVertex: public PrimitivesError
{
public:
    LackOfVertex(const string file_, long line_n_);
    virtual ~LackOfVertex();
};

class VertexUndefinded: public PrimitivesError
{
public:
    VertexUndefinded(const string file_, long line_n_);
    virtual ~VertexUndefinded();
};

} // err::

#endif // PRIMITIVES_ERROR_H
