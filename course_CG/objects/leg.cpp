#include "leg.h"
#include "visitors/object_visitor.h"

TableLeg::TableLeg(double x, double z, double h)
{
    _color = QColor(121, 79, 39).rgba();
    Point p1(x-_wide, 0, z-_wide);
    Point p2(x+_wide, h, z+_wide);
    Model* m_ptr = new SimpleBox(_color, p1, p2);
    this->_model = shared_ptr<Model>(m_ptr);
}
TableLeg::TableLeg(const TableLeg& other): VisibleObject(other)
{
    _color = other._color;
}
TableLeg::~TableLeg() {}


void TableLeg::accept(ObjectVisitor& visitor)
{
    visitor.visit(*this);
}
SceneObject* TableLeg::clone()
{
    return (new TableLeg(*this));
}
