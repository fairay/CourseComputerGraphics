#include "table.h"
#include "visitors/object_visitor.h"

Table::Table()
{
    _init_models();
}
Table::Table(double leg_h, double len, double wide, double r)
{
    _leg_h = leg_h;
    _len = len;
    _wide = wide;
    _hole_r = 1.75 * r;
    _init_models();
}
Table::Table(const Table& other): CompositeObject (other)
{
    _leg_h = other._leg_h;
    _len = other._len;
    _wide = other._wide;
    _hole_r = other._hole_r;
}
Table::~Table() {}

void Table::accept(ObjectVisitor& visitor)
{
    visitor.visit(*this);
}
SceneObject* Table::clone()
{
    return (new Table(*this));
}

Point Table::get_max_border() { return Point( _wide/2,  _leg_h+_plate_h,    _len/2); }
Point Table::get_min_border() { return Point(-_wide/2,  _leg_h+_plate_h,   -_len/2); }

void Table::_init_models()
{
    _init_legs();
    _init_plates();
    _init_rails();
}
void Table::_init_legs()
{
    double x_off = 0.8 * _wide/2;
    double z_off = 0.8 * _len/2;
    add_object(new TableLeg(-x_off, -z_off, _leg_h));
    add_object(new TableLeg(x_off, -z_off, _leg_h));
    add_object(new TableLeg(-x_off, z_off, _leg_h));
    add_object(new TableLeg(x_off, z_off, _leg_h));
}
void Table::_init_plates()
{
    add_object(new Plate(_leg_h, _wide+_rail_w*2+1, _len+_rail_w*2+1));
    add_object(new Plate(_leg_h+_plate_h, _wide, _len, _hole_r, true));
    add_object(new Plate(_leg_h+_plate_h, _wide, _len, _hole_r, false));
}
void Table::_init_rails()
{
    Point p1(_wide/2, _leg_h+_plate_h, _len/2);
    Point p12(_wide/2, _leg_h+_plate_h, 0);
    Point p13(0, _leg_h+_plate_h, _len/2);
    Point p24(0, _leg_h+_plate_h, -_len/2);
    Point p2(_wide/2, _leg_h+_plate_h, -_len/2);

    add_object(new SideRail(p1, p12, _hole_r, _rail_w));
    add_object(new SideRail(p2, p12, _hole_r, _rail_w));
    add_object(new HeadRail(p1, p13, _hole_r, _rail_w));
    add_object(new HeadRail(p2, p24, _hole_r, _rail_w));

    p1.x = -p1.x; p12.x = -p12.x; p2.x = -p2.x;
    add_object(new SideRail(p1, p12, _hole_r, _rail_w));
    add_object(new SideRail(p2, p12, _hole_r, _rail_w));
    add_object(new HeadRail(p1, p13, _hole_r, _rail_w));
    add_object(new HeadRail(p2, p24, _hole_r, _rail_w));
}
