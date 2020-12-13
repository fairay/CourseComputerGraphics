#include "update_mng.h"

using namespace manager;

InitUpdaterManager::InitUpdaterManager(weak_ptr<Scene> scene_ptr):
    IManager(scene_ptr) {}
InitUpdaterManager::~InitUpdaterManager() {}
void InitUpdaterManager::execute()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "Init Updater Manager");
    shared_ptr<Updater> upd = _scene.lock()->get_updater();
    upd->reset();

    shared_ptr<ObjectVisitor> visitor(new InitUpdVisitor(upd));
    for (auto obj: *_scene.lock())
        obj->accept(*visitor);
}


UpdateManager::UpdateManager(weak_ptr<Scene> scene_ptr):
    IManager(scene_ptr) {}
UpdateManager::~UpdateManager() {}
void UpdateManager::execute()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "Update Manager");
    shared_ptr<Updater> upd = _scene.lock()->get_updater();
    double dt = _scene.lock()->get_dt();

    upd->update(dt);
}

#include "visual/visualizer.h"
ShotManager::ShotManager(weak_ptr<Scene> scene_ptr, const Point& click_p, double power):
    IManager(scene_ptr), _click_p(click_p), _power(power) {}
ShotManager::~ShotManager() {}
void ShotManager::execute()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "Shot Manager");

    cout << "*** IAM HERE" << endl;
    shared_ptr<Scene> scene = _scene.lock();
    shared_ptr<Updater> upd = scene->get_updater();
    if (!upd->is_motionless())
        return;

    shared_ptr<Visualizer> visual(new Visualizer());
    visual->set_camera(*scene->get_camera());
    Point p1 = upd->get_min_point();
    Point p2 = upd->get_max_point();
    Point p3(p1.x, p2.y, p2.z);


    p1 = visual->proj_point(p1);
    p2 = visual->proj_point(p2);
    p3 = visual->proj_point(p3);

    double a = p1.y*(p2.z-p3.z) + p2.y*(p3.z-p1.z) + p3.y*(p1.z-p2.z);
    double b = p1.z*(p2.x-p3.x) + p2.z*(p3.x-p1.x) + p3.z*(p1.x-p2.x);
    double c = p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y) + p3.x*(p1.y-p2.y);
    double d = -p1.x*(p2.y*p3.z - p3.y*p2.z) - p2.x*(p3.y*p1.z - p1.y*p3.z) - p3.x*(p1.y*p2.z - p2.y*p1.z);
    _click_p.z = -(a*_click_p.x + b*_click_p.y + d)/c;

    Point proj = visual->reproj_point(_click_p);

//    if (upd->is_out(proj))
//    {
//        cout << "______________ DENIED" << endl;
//        return;
//    }

    upd->make_hit(proj, _power);
}
