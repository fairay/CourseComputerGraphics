#include "rails.h"
#include "visitors/object_visitor.h"

Rail::Rail()
{
    QColor col;
    col.setRgb(101, 67, 33);
    _color = col.rgba();
}
Rail::Rail(const Rail& other): VisibleObject(other)
{
    _color = other._color;
}
Rail::~Rail() {}
void Rail::accept(ObjectVisitor& visitor)
{
    visitor.visit(*this);
}
SceneObject* Rail::clone()
{
    return (new Rail(*this));
}


SideRail::SideRail(const Point& cor_p, const Point& mid_p, double R): Rail()
{
    Model* m_ptr = new LongSkirting(_color, cor_p, mid_p, _hu, _hd, _w, R);
    this->_model = shared_ptr<Model>(m_ptr);
}
SideRail::SideRail(const SideRail& other): Rail(other) {}
SideRail::~SideRail() {}


HeadRail::HeadRail(const Point& cor_p, const Point& mid_p, double R): Rail()
{
    Model* m_ptr = new ShortSkirting(_color, cor_p, mid_p, _hu, _hd, _w, R);
    this->_model = shared_ptr<Model>(m_ptr);
}
HeadRail::HeadRail(const HeadRail& other): Rail(other) {}
HeadRail::~HeadRail() {}
