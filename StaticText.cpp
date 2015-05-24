#include "StaticText.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace std;
using namespace genv;

StaticText::StaticText(Application* ap, int x, int y, int sx, int sy, string txt, string al, string col)
    : Widget(ap,x,y,sx,sy)
    {
        focusable = false;
        focused = false;
        value = txt;
        align = al;
        color = col;

        Widget::Load(ap);
    }

void StaticText::Draw()
{

   Widget::SetColor(color);
    if(align == "left")
    {
        Widget::WriteTextAlignLeft(value);
    }
    else if(align == "center")
    {
        Widget::WriteTextAlignCenter(value);

    }
    else if(align == "right")
    {
        Widget::WriteTextAlignRight(value);
    }

}

void StaticText::SetValue(string txt)
{
    value = txt;
}

string StaticText::GetValue()
{
    return value;
}
