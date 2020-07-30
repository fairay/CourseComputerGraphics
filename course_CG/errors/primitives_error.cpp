#include "primitives_error.h"

using namespace err;
PrimitivesError::PrimitivesError(const string file_, long line_n_):
    SceneError(file_, line_n_)
{
    type = "Primitives error: ";
}
PrimitivesError::~PrimitivesError() = default;



LackOfVertex::LackOfVertex(const string file_, long line_n_):
    PrimitivesError(file_, line_n_)
{
    type += "lack of vertex";
    add_info = "not enough vetrex to create polygon";
    fill_msg();
}
LackOfVertex::~LackOfVertex() = default;

VertexUndefinded::VertexUndefinded(const string file_, long line_n_):
    PrimitivesError(file_, line_n_)
{
    type += "vertex undefinded";
    add_info = "index of vertex are not in model";
    fill_msg();
}
VertexUndefinded::~VertexUndefinded() = default;
