#include "cue_ball.h"
#include "visitors/object_visitor.h"

CueBall::CueBall(const Point& pos_, double r_, QRgb color_, bool is_main):
    r(r_), pos(pos_), v(0, 0, 0), _is_main(is_main)
{
    _color = color_;
    Model* m_ptr = new BallModel(_color, r, pos);
    this->_model = shared_ptr<Model>(m_ptr);
}
CueBall::CueBall(const CueBall& other):
    VisibleObject(other), r(other.r), pos(other.pos), v(other.v)
{
    _color = other._color;
    _is_main = other._is_main;
}
CueBall::~CueBall() { cout << _self_ptr.use_count() << endl; _self_ptr.reset(); }

void CueBall::accept(ObjectVisitor& visitor)
{
    visitor.visit(*this);
}
SceneObject* CueBall::clone()
{
    return (new CueBall(*this));
}

bool CueBall::is_main() { return _is_main; }

void CueBall::move(const Vector &v)
{
    pos.move(v);
    _model->move(v);
}



void CueBall::set_ptr(const shared_ptr<CueBall>& self_ptr)
{
    _self_ptr = self_ptr;
}
shared_ptr<CueBall> CueBall::get_ptr() {return  _self_ptr; }
