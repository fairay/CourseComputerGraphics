#ifndef RAILS_H
#define RAILS_H

#include "simple_object.h"
#include "3d_prmitives/skirting.h"



class Rail: public VisibleObject
{
public:
    Rail();
    explicit Rail(const Rail& other);
    virtual ~Rail();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();
protected:
    QRgb _color;
    const double _w = 170;
    const double _hu = 100, _hd = 100;
};


class SideRail: public Rail
{
public:
    SideRail(const Point& cor_p, const Point& mid_p, double R);
    explicit SideRail(const SideRail& other);
    virtual ~SideRail();
};

class HeadRail: public Rail
{
public:
    HeadRail(const Point& cor_p, const Point& mid_p, double R);
    explicit HeadRail(const HeadRail& other);
    virtual ~HeadRail();
};

#endif // RAILS_H
