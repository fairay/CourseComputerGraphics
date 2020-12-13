#include "objects.h"
using namespace err;


ObjectError::ObjectError(const string file_, long line_n_): SceneError(file_, line_n_)
{
    type = "Object Error: ";
}
ObjectError::~ObjectError() = default;



NotDrawable::NotDrawable(const string file_, long line_n_): ObjectError(file_, line_n_)
{
    type += "NotDrawable";
    add_info = "object is not drawable";
    fill_msg();
}
NotDrawable::~NotDrawable() = default;

NotTransable::NotTransable(const string file_, long line_n_): ObjectError(file_, line_n_)
{
    type += "NotTransable";
    add_info = "object can't be transleeted";
    fill_msg();
}
NotTransable::~NotTransable() = default;

UndefindeVisiter::UndefindeVisiter(const string file_, long line_n_): ObjectError(file_, line_n_)
{
    type += "UndefindeVisiter";
    add_info = "operation of visit isn't defided for object";
    fill_msg();
}
UndefindeVisiter::~UndefindeVisiter() = default;

UndefindeClone::UndefindeClone(const string file_, long line_n_): ObjectError(file_, line_n_)
{
    type += "UndefindeClone";
    add_info = "operation of clone isn't defided for object";
    fill_msg();
}
UndefindeClone::~UndefindeClone() = default;



VisitorError::VisitorError(const string file_, long line_n_): ObjectError(file_, line_n_)
{
    type += "Visitor Error: ";
}
VisitorError::~VisitorError() = default;

VisualExpired::VisualExpired(const string file_, long line_n_): VisitorError(file_, line_n_)
{
    type += "Visual Expired";
    add_info = "pointer of Visualisator has expired";
    fill_msg();
}
VisualExpired::~VisualExpired() = default;

TransExpired::TransExpired(const string file_, long line_n_): VisitorError(file_, line_n_)
{
    type += "Trans Expired";
    add_info = "pointer of Transformation has expired";
    fill_msg();
}
TransExpired::~TransExpired() = default;


MainBallScored::MainBallScored(const string file_, long line_n_): VisitorError(file_, line_n_)
{
    type += "Main Ball Scored";
    add_info = "main ball scored, game over";
    fill_msg();
}
MainBallScored::~MainBallScored() = default;

