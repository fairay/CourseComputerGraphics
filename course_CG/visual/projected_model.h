#ifndef PROJECTED_MODEL_H
#define PROJECTED_MODEL_H

#include "3d_prmitives/model.h"


class ProjEdge
{
public:
    double x, x0;
    double z, z0;
    double dx, dz;
    double i, i0, di;
    int y, y0, ymax;

    ProjEdge(Point& p1, double i1,
             Point& p2, double i2);
    ProjEdge(const ProjEdge& other);
    ~ProjEdge();

    void reset();
    void print();
    bool step(); // returns is_done

    bool is_done() const;
    bool is_horizontal() const;
};


class ProjSide
{
public:
    vector<ProjEdge> edges;
    vector<ProjEdge> waiting_edges;
    vector<ProjEdge> active_edges;
    int temp_y;

    ProjSide();
    ProjSide(ProjSide&& other);
    ~ProjSide();

    void init();
    void add_edge(const ProjEdge& edge);
    bool step(); // returns is_done
    bool is_done();
    bool is_empty();
private:
};


class ProjModel
{
    ProjModel();
    ~ProjModel();

};

#endif // PROJECTED_MODEL_H
