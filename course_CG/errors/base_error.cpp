#include <ctime>
#include "base_error.h"

using namespace err;

/// err::List
SceneError::SceneError(const string file_, long line_n_): file(file_)
{
    line_n = to_string(line_n_);
    err_time = cur_time();
}
SceneError::~SceneError()
{
    delete []err_msg;
}

// private
string SceneError::cur_time()
{
    const time_t cur_t = time(nullptr);
    string str = asctime(localtime(&cur_t));
    return str;
}
string SceneError::base_msg()
{
    string msg = "Scene error! \n"
                 "File " + file + ":" + line_n + "\t" + err_time;
    return msg;
}
string SceneError::add_msg()
{
    string msg = "";
    if (type == "")     return msg;
    msg += "Type: " + type;

    if (add_info == "") return msg;
    msg += " : " + add_info;
    return msg;
}

// protected
void SceneError::fill_msg()
{
    string msg = base_msg() + "\n" + add_msg();
    err_msg = new char[msg.length()+1];
    strcpy(err_msg, msg.c_str());
}

// public
const char* SceneError::what() const noexcept
{
    return err_msg;
}

