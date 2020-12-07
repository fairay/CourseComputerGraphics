#include "draw.h"

DrawVisitor::DrawVisitor(shared_ptr<Visualizer>& visual):
    _visual(visual) {}
DrawVisitor::~DrawVisitor() {}

void DrawVisitor::visit(Camera&) {}
void DrawVisitor::visit(LightSource&) {}

void DrawVisitor::visit(TableLeg& obj)
{
    _visual->draw_model(*obj.get_model());
}
void DrawVisitor::visit(CueBall& obj)
{
    _visual->draw_model(*obj.get_model());
}
void DrawVisitor::visit(Plate &obj)
{
    _visual->draw_model(*obj.get_model());
}
void DrawVisitor::visit(Rail& obj)
{
    _visual->draw_model(*obj.get_model());
}


ShadowVisitor::ShadowVisitor(shared_ptr<Visualizer>& visual):
    _visual(visual) {}
ShadowVisitor::~ShadowVisitor() {}

void ShadowVisitor::visit(Camera&) {}
void ShadowVisitor::visit(LightSource&) {}

void ShadowVisitor::visit(TableLeg& obj)
{
    _visual->draw_shadow(*obj.get_model());
}
void ShadowVisitor::visit(CueBall& obj)
{
    _visual->draw_shadow(*obj.get_model());
}
void ShadowVisitor::visit(Plate &obj)
{
    _visual->draw_shadow(*obj.get_model());
}
void ShadowVisitor::visit(Rail &obj)
{
    _visual->draw_shadow(*obj.get_model());
}
