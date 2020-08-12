#ifndef TRANSFORMATOR_H
#define TRANSFORMATOR_H

#include "trans_action.h"
#include "memory"

using namespace std;
class Transformator
{
public:
    Transformator(Action* trans): _trans(trans) {}
    ~Transformator() {}

    void set_trans(Action* trans)
    { _trans = unique_ptr<Action>(trans);}
    void transform(double& x, double& y, double& z)
    { _trans->execute(x, y, z); }
    void transform(Vertex& p)
    { _trans->execute(p); }
    void transform(Point& p)
    { _trans->execute(p); }
    void transform(Vector& p)
    { _trans->execute(p); }
    void transform(Camera& p)
    { _trans->execute(p); }
private:
    unique_ptr<Action> _trans;
};

#endif // TRANSFORMATOR_H
