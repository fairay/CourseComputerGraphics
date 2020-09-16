#include "leg.h"
#include "visitors/object_visitor.h"

TableLeg::TableLeg(double x, double y, double h)
{
    _color = QColor(Qt::green).rgba();
    Point p1(x-_wide, y-_wide, 0);
    Point p2(x+_wide, y+_wide, h);
    Model* m_ptr = new BoxModel(_color, p1, p2);
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
