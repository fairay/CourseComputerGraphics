#ifndef BASE_ERROR_H
#define BASE_ERROR_H

#include <exception>
#include <cstring>
#include <iostream>

using namespace std;
namespace err {

class SceneError: exception
{
public:
    SceneError(const string file_, long line_n_);
    virtual ~SceneError() override;
    virtual const char* what() const noexcept override;
protected:
    char* err_msg;
    void fill_msg();
    string type = "";
    string add_info = "";
private:
    string file;
    string line_n;
    string err_time;

    string cur_time();
    string base_msg();
    string add_msg();
};

} // namespace err


#endif // BASE_ERROR_H
