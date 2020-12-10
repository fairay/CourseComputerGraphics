#ifndef UPDATE_VISITOR_H
#define UPDATE_VISITOR_H

#include "object_visitor.h"
#include "updater/updater.h"

class InitUpdVisitor: public ObjectVisitor
{
public:
    InitUpdVisitor(shared_ptr<Updater>&);
    virtual ~InitUpdVisitor();

    virtual void visit(Camera& obj);
    virtual void visit(LightSource& obj);

    virtual void visit(TableLeg& obj);
    virtual void visit(CueBall& obj);
    virtual void visit(Plate& obj);
    virtual void visit(Rail& obj);

    virtual void visit(Table& obj);

private:
    shared_ptr<Updater> _upd;
};



#endif // UPDATE_VISITOR_H
