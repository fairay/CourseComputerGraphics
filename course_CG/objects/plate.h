#ifndef PLATE_H
#define PLATE_H

#include "simple_object.h"
#include "3d_prmitives/box_model.h"

class Plate: public VisibleObject
{
public:
    Plate(double h, double wide, double len , bool is_up); // top plate
    Plate(double h, double wide, double len);               // bottom plate
    explicit Plate(const Plate& other);
    virtual ~Plate();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();
private:
    QRgb _color;
};


#endif // PLATE_H
