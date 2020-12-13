#include "build_mng.h"
#include "update_mng.h"

using namespace manager;

BuildManager::BuildManager(weak_ptr<Scene> scene_ptr, string f_name):
    IManager(scene_ptr), _f_name(f_name) {}
BuildManager::~BuildManager()
{
    if (_file.is_open())
        _file.close();
}
void BuildManager::execute()
{
    cout << "ENTER BUILDER" << endl;
    _file.open(_f_name);
    if (!_file)
        throw err::FileOpenFail(__FILE__, __LINE__-2, _f_name);

    double h, l, w;
    _file >> h >> l >> w;
    h *= 10; l*=10; w*=10;
    if (h < MIN_H_TABLE || l < MIN_LW_TABLE || w < MIN_LW_TABLE)
        throw err::WrongTableSize(__FILE__, __LINE__-1);

    double R;
    _file >> R;
    R*=10;
    if (R < MIN_BALL_R || R > w/10 || R > l/10)
        throw err::WrongBallR(__FILE__, __LINE__-1);

    size_t ball_n;
    _file >> ball_n;
    if (ball_n <= 0)
        throw err::WrongBallCount(__FILE__, __LINE__-1);

    double max_x = w - R*(sqrt(2) + 1);
    double max_z = l - R*(sqrt(2) + 1);
    double ball_h = h + R + 100;
    vector<Point> pos_arr;
    for (size_t i=0; i<ball_n; i++)
    {
        Point p(0, ball_h, 0);
        _file >> p.x >> p.z;
        p.x*=10; p.z*=10;
        if (p.x < -max_x || p.x > max_x)
            throw err::WrongBallPosition(__FILE__, __LINE__-1);
        if (p.z < -max_z || p.z > max_z)
            throw err::WrongBallPosition(__FILE__, __LINE__-1);
        pos_arr.push_back(p);
    }

    for (size_t i=0; i<pos_arr.size(); i++)
        for (size_t j=i+1; j<pos_arr.size(); j++)
            if (pos_arr[i].distance2d(pos_arr[j]) < 2*R)
                throw err::WrongBallPosition(__FILE__, __LINE__-1);

    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "Build Manager");
    shared_ptr<Scene> scene = _scene.lock();

    cout << "&&&" << endl;
    scene->clear_obj();
    scene->add_object(new Table(h, l, w, R));
    scene->add_main_ball(pos_arr[0], R);
    cout << "&&&" << endl;
    for (size_t i=1; i<pos_arr.size(); i++)
    {
        cout << "ADD BALL ";
        pos_arr[i].print();
        scene->add_ball(pos_arr[i], R);
    }

    manager::InitUpdaterManager(_scene).execute();
    // new_arr.push_back(shared_ptr<SceneObject>(new CueBall(pos_arr[0], R, )));
}
