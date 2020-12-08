#include "plate.h"
#include "3d_prmitives/mplate.h"
#include "visitors/object_visitor.h"

Plate::Plate(double h, double len, double wide, bool is_up)
{
    _color = QColor(Qt::darkGreen).rgba();
    Point p0(-len/2, h+_height, 0), p1;
    if (is_up)
        p1 = Point(len/2, h+_height, wide/2);
    else
        p1 = Point(len/2, h+_height, -wide/2);
//    Point p1(len/2, h+_height, wide/2);
//    Point p2(-len/2, h+_height, -wide/2);
    Model* m_ptr = new TopPlateModel(_color, p1, p0, 100);
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
