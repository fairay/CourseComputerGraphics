#ifndef OBJECT_VISITOR_H
#define OBJECT_VISITOR_H

#include "objects/camera.h"
#include "objects/leg.h"
#include "objects/light_source.h"

class ObjectVisitor
{
public:
    ObjectVisitor();
    virtual ~ObjectVisitor() = 0;

    virtual void visit(Camera& point) = 0;
    virtual void visit(LightSource& point) = 0;

    virtual void visit(TableLeg& point) = 0;
};

#endif // OBJECT_VISITOR_H
