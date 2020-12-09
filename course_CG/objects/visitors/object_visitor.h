#ifndef OBJECT_VISITOR_H
#define OBJECT_VISITOR_H

#include "objects/camera.h"
#include "objects/light_source.h"

#include "objects/leg.h"
#include "objects/cue_ball.h"
#include "objects/plate.h"
#include "objects/rails.h"
#include "objects/table.h"

class ObjectVisitor
{
public:
    ObjectVisitor();
    virtual ~ObjectVisitor() = 0;

    virtual void visit(Camera& point) = 0;
    virtual void visit(LightSource& point) = 0;

    virtual void visit(TableLeg& point) = 0;
    virtual void visit(CueBall& point) = 0;
    virtual void visit(Plate& point) = 0;
    virtual void visit(Rail& point) = 0;
    virtual void visit(Table& point) = 0;
};

#endif // OBJECT_VISITOR_H
