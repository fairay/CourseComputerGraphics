#include "plate.h"
#include "visitors/object_visitor.h"

Plate::Plate(double h, double len, double wide)
{
    _color = QColor(Qt::green).rgba();
    Point p1(len/2, h, wide/2);
    Point p2(-len/2, h+_height, -wide/2);
    Model* m_ptr = new DetailBox(_color, p1, p2);
    this->_model = shared_ptr<Model>(m_ptr);
}
Plate::Plate(const Plate& other): VisibleObject(other)
{
    _color = other._color;
}
Plate::~Plate() {}


void Plate::accept(ObjectVisitor& visitor)
{
    visitor.visit(*this);
}
SceneObject* Plate::clone()
{
    return (new Plate(*this));
}
