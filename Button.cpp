#include "Button.hpp"
using namespace std;
using namespace genv;

Button::Button(Application *ap, int x, int y, int sx, int sy, string val, function<void()> f)
    : Widget(ap,x,y,sx,sy)
    {
        focusable = true;
        focused = false;
        fv = f;
        value = val;
        pushed = false;

        Widget::Load(ap);
    }

void Button::Draw()
{
    gout << move_to(coord_x, coord_y) << color(145,145,145) << box(size_x, size_y);
    gout << move_to(coord_x + (size_x -gout.twidth(value))/2, coord_y+(size_y/2)+ gout.cdescent()) << color(255,255,255) << text(value);

    if(focused)
    {
        Widget::DrawFocused();
    }
}

void Button::EventHandler(event ev)
{

    if(ev.button == btn_left)
    {
        fv();
    }

}
