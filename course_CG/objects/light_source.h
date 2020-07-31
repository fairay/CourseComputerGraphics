#ifndef LIGHT_SOURCE_H
#define LIGHT_SOURCE_H

#include "simple_object.h"

class LightSource: public InvisibleObject
{
public:
    LightSource();
    LightSource(const Point& pos);
    LightSource(const Point& pos, double intensity);
    explicit LightSource(const LightSource& other);
    virtual ~LightSource();

    Point& get_pos();
    const Point& get_pos() const;
    double get_intensity() const;
    void set_intensity(double);

    virtual void accept(ObjectVisitor&);
    virtual SceneObject* clone();

private:
    Point _pos;
    double _i;
};

#endif // LIGHT_SOURCE_H
