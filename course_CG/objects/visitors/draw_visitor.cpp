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

