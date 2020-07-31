#include "camera.h"

Camera::Camera(): _pos(Point(0, 0, 1000)) {}
Camera::Camera(const Point& pos): _pos(pos) {}
Camera::Camera(const Point& pos, const Vector& dir):
    _pos(pos), _dir(dir) {}
Camera::Camera(const Camera& other)
{
    this->_pos = other._pos;
    this->_dir = other._dir;
}
Camera::~Camera() {}

Point& Camera::get_pos() { return _pos; }
Vector& Camera::get_dir() { return _dir; }
const Point& Camera::get_pos() const  { return _pos; }
const Vector& Camera::get_dir() const { return _dir; }

void Camera::accept(ObjectVisitor& visitor)
{

}

SceneObject* Camera::clone()
{
    return (new Camera(*this));
}
