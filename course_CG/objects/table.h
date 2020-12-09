#ifndef TABLE_H
#define TABLE_H

#include "composite_object.h"

#include "leg.h"
#include "plate.h"
#include "rails.h"


class Table: public CompositeObject
{
public:
    Table();
    Table(double leg_h, double len, double wide, double r);
    explicit Table(const Table& other);
    virtual ~Table();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();
private:
    double _leg_h = 750;
    double _len = 2800;
    double _wide = 1530;
    double _hole_r = 100;

    const double _plate_h = 100;
    const double _rail_w = 100;

    void _init_models();
    void _init_legs();
    void _init_plates();
    void _init_rails();
};

#endif // TABLE_H
