#ifndef DRAW_VISITOR_H
#define DRAW_VISITOR_H

#include "object_visitor.h"
#include "visual/visualizer.h"

class DrawVisitor: public ObjectVisitor
{
public:
    DrawVisitor(shared_ptr<Visualizer>&);
    virtual ~DrawVisitor();

    virtual void visit(Camera& obj);
    virtual void visit(LightSource& obj);

    virtual void visit(TableLeg& obj);
    virtual void visit(CueBall& obj);
    virtual void visit(Plate& point);
private:
    shared_ptr<Visualizer> _visual;
};

#endif // DRAW_H
