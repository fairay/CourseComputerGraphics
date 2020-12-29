#include "update_visitor.h"


InitUpdVisitor::InitUpdVisitor(shared_ptr<Updater>& upd):
    _upd(upd) {}
InitUpdVisitor::~InitUpdVisitor() {}

void InitUpdVisitor::visit(Camera&) {}
void InitUpdVisitor::visit(LightSource&) {}

void InitUpdVisitor::visit(TableLeg&) {}
void InitUpdVisitor::visit(CueBall& obj)
{
    _upd->add_ball(obj.get_ptr());
}
void InitUpdVisitor::visit(Plate&) {}
void InitUpdVisitor::visit(Rail& obj)
{
    _upd->add_long_rail(obj.cor_top, obj.mid_top,
                        obj.cor_back, obj.mid_back);
}

void InitUpdVisitor::visit(Table& obj)
{
    _upd->add_borders(obj.get_min_border(), obj.get_max_border());
    for (auto sub_obj: obj)
        sub_obj->accept(*this);
}





PostUpdVisitor::PostUpdVisitor(shared_ptr<Updater>& upd):
    _upd(upd) {}
PostUpdVisitor::~PostUpdVisitor() {}

void PostUpdVisitor::visit(Camera&) {}
void PostUpdVisitor::visit(LightSource&) {}

void PostUpdVisitor::visit(TableLeg&) {}
void PostUpdVisitor::visit(CueBall& obj)
{
    // _upd->add_ball(obj.get_ptr());
    if (_upd->is_scored(obj))
    {
        if (obj.is_main())
            throw 2;
        else
            throw 1;
    }
}
void PostUpdVisitor::visit(Plate&) {}
void PostUpdVisitor::visit(Rail&) {}

void PostUpdVisitor::visit(Table&) {}

