#include "cue_ball.h"
#include "visitors/object_visitor.h"

CueBall::CueBall(const Point& pos, double r, QRgb color_)
{
    _color = color_;
    _r = r;
    Model* m_ptr = new BallModel(_color, _r, pos);
    this->_model = shared_ptr<Model>(m_ptr);
}
CueBall::CueBall(const CueBall& other): VisibleObject(other)
{
    _color = other._color;
}
CueBall::~CueBall() {}

void CueBall::accept(ObjectVisitor& visitor)
{
    visitor.visit(*this);
}
SceneObject* CueBall::clone()
{
    return (new CueBall(*this));
}
