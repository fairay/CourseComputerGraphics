#ifndef COMPOSITE_OBJECT_H
#define COMPOSITE_OBJECT_H

#include "scene_object.h"
#include "3d_prmitives/model.h"
#include <vector>

using obj_arr = std::vector<shared_ptr<SceneObject>>;
using iter_obj = obj_arr::iterator;
using citer_obj = obj_arr::const_iterator;

class CompositeObject: public SceneObject
{
public:
    CompositeObject();
    explicit CompositeObject(const CompositeObject& other);
    virtual ~CompositeObject();

    virtual bool is_complex() const final {return true;}
    virtual bool is_observer() const final {return false;}
    virtual bool is_drawable() const final {return true;}

    iter_obj begin() {return _obj_arr.begin();}
    iter_obj end() {return _obj_arr.end();}
    citer_obj begin() const {return _obj_arr.begin();}
    citer_obj end() const {return _obj_arr.end();}
    citer_obj cbegin() {return _obj_arr.cbegin();}
    citer_obj cend() {return _obj_arr.cend();}

    size_t get_size() const {return _obj_arr.size();}

    void add_object(SceneObject* obj);
    void add_object(shared_ptr<SceneObject> obj);
    void remove_object(iter_obj& iter);

protected:
    obj_arr _obj_arr;
};

#endif // COMPOSITE_OBJECT_H
