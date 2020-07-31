#ifndef CAMERA_H
#define CAMERA_H

#include "simple_object.h"

class Camera: public InvisibleObject
{
public:
    Camera();
    Camera(const Point& pos);
    Camera(const Point& pos, const Vector& dir);
    explicit Camera(const Camera& other);
    virtual ~Camera();

    Point& get_pos();
    Vector& get_dir();
    const Point& get_pos() const;
    const Vector& get_dir() const;

    virtual void accept(ObjectVisitor&);
    virtual SceneObject* clone();

private:
    Point _pos;
    Vector _dir;
};

#endif // CAMERA_H
