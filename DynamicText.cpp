#include "DynamicText.hpp"
#include <iostream>
using namespace std;
using namespace genv;

DynamicText::DynamicText(Application* ap, int x, int y, int sx, int sy, string txt)
    : Widget(ap,x,y,sx,sy)
    {
        focusable = true;
        focused = false;
        value = txt;
        Widget::Load(ap);
    }

void DynamicText::Draw()
{
    SetColor("border");
    Widget::DrawBorder();
    SetColor("text1");
    WriteTextAlignLeft(value);

    if(focused)
    {
        SetColor("focus");
        Widget::DrawFocused();
        SetColor("border");
        gout << move_to(gout.twidth(value)+coord_x+1, coord_y + 2) << line(0,size_y-4);
    }
}

void DynamicText::EventHandler(event ev)
{
    if(ev.type == ev_key)
    {
        if(gout.twidth(value) < size_x - gout.twidth(" ") && ev.keycode != 8) value += ev.keycode;
        if(ev.keycode == 8 && value.size() > 0) value.erase(value.size()-1);
    }
}

void DynamicText::SetValue(string txt)
{
    value = txt;
}

string DynamicText::GetValue()
{
    return value;
}
