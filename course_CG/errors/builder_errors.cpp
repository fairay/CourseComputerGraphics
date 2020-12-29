#include "builder_errors.h"

using namespace err;
BuilderError::BuilderError(const string file_, long line_n_): SceneError(file_, line_n_)
{
    type = "BuilderError: ";
}
BuilderError::~BuilderError() = default;



FileOpenFail::FileOpenFail(const string file_, long line_n_, const string name_):
    BuilderError(file_, line_n_)
{
    type += "FileOpenFail";
    add_info = "failed to open file: " + name_;
    fill_msg();
}
FileOpenFail::~FileOpenFail() = default;

FileNotOpen::FileNotOpen(const string file_, long line_n_):
    BuilderError(file_, line_n_)
{
    type += "FileNotOpen";
    add_info = "requesting scan operation while file isn't open";
    fill_msg();
}
FileNotOpen::~FileNotOpen() = default;

WrongBallR::WrongBallR(const string file_, long line_n_):
    BuilderError(file_, line_n_)
{
    type += "WrongBallR";
    add_info = "ball radius is too small";
    fill_msg();
}
WrongBallR::~WrongBallR() = default;

WrongBallCount::WrongBallCount(const string file_, long line_n_):
    BuilderError(file_, line_n_)
{
    type += "WrongBallCount";
    add_info = "not enough balls in file";
    fill_msg();
}
WrongBallCount::~WrongBallCount() = default;

WrongTableSize::WrongTableSize(const string file_, long line_n_):
    BuilderError(file_, line_n_)
{
    type += "WrongTableSize";
    add_info = "scaned incorrect sizes of table";
    fill_msg();
}
WrongTableSize::~WrongTableSize() = default;



WrongBallPosition::WrongBallPosition(const string file_, long line_n_):
    BuilderError(file_, line_n_)
{
    type += "WrongBallPosition";
    add_info = "ball position is out of table";
    fill_msg();
}
WrongBallPosition::~WrongBallPosition() = default;
