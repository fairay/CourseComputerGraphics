#ifndef LEG_H
#define LEG_H

#include "simple_object.h"
#include "3d_prmitives/box_model.h"

class TableLeg: public VisibleObject
{
public:
    TableLeg(double x, double z, double h);
    explicit TableLeg(const TableLeg& other);
    virtual ~TableLeg();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
    const double _wide = 100;
};

#endif // LEG_H
