#ifndef PLATE_H
#define PLATE_H

#include "simple_object.h"
#include "3d_prmitives/box_model.h"

class Plate: public VisibleObject
{
public:
    Plate(double h, double len, double wide);
    explicit Plate(const Plate& other);
    virtual ~Plate();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();
private:
    QRgb _color;
    const double _height = 100;// 100;
};


#endif // PLATE_H
