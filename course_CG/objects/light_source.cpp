#include "light_source.h"
#include "visitors/object_visitor.h"

LightSource::LightSource():_pos(Point(0, 0, 2000)) {}
LightSource::LightSource(const Point& pos): _pos(pos) {}
LightSource::LightSource(const Point& pos, double intensity):
    _pos(pos), _i(intensity) {}
LightSource::LightSource(const LightSource& other)
{
    this->_pos = other._pos;
    this->_i = other._i;
}
LightSource::~LightSource() {}


Point& LightSource::get_pos() { return _pos; }
const Point& LightSource::get_pos() const  { return _pos; }
double LightSource::get_intensity() const { return _i; }
void LightSource::set_intensity(double i) { _i = i; }


void LightSource::accept(ObjectVisitor& visitor)
{
    visitor.visit(*this);
}
SceneObject* LightSource::clone()
{
    return (new LightSource(*this));
}
