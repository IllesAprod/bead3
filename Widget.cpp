#include "Widget.hpp"
#include "Application.hpp"
#include "graphics.hpp"
#include "Colors.hpp"
#include <iostream>

using namespace std;
using namespace genv;

/*** CONSTRUCTOR ***/

Widget::Widget(Application* ap, int x, int y, int sx, int sy)
    : AppPointer(ap), coord_x(x), coord_y(y), size_x(sx), size_y(sy)
    {

    }

/*** FUNCTIONS ***/

bool Widget::GetFocusable()
{
    return focusable;
}

bool Widget::GetFocused()
{
    return focused;
}

void Widget::DrawFocused()
{
    SetColor("focus");
    for (int i=-1; i<size_x+2; i++)
    {
        if(i%2 == 0)
        {
            gout << move_to(coord_x + i, coord_y-2) << dot;
            gout << move_to(coord_x + i, coord_y + size_y + 1) << dot;
        }
    }
    for (int i=-1; i<size_y+2; i++)
    {
        if(i%2 == 0)
        {
            gout << move_to(coord_x - 2, coord_y + i) << dot;
            gout << move_to(coord_x + size_x + 1, coord_y + i) << dot;
        }
    }

}

void Widget::SetFocusOn()
{
    focused = true;
}

void Widget::SetFocusOff()
{
    focused = false;
}

bool Widget::GetOnMe(int x, int y)
{
    if (x >=  coord_x && x < coord_x + size_x && y >= coord_y && y < coord_y+size_y) return true;
    else return false;
}

/*** GRAPHICS FUNCTIONS ***/

void Widget::DrawBorder()
{
    gout
    << move_to (coord_x, coord_y)
    << line(size_x, 0)
    << line(0, size_y)
    << line(-size_x, 0)
    << line(0, -size_y);
}


void Widget::SetColor(string ColorName)
{
    string color_s;
    if(ColorName == "bg") gout << color(BgColorR, BgColorG, BgColorB);
    else if(ColorName == "border") gout << color(BorderColorR, BorderColorG, BorderColorB);
    else if(ColorName == "focus") gout << color(FocusColorR, FocusColorG, FocusColorB);
    else if(ColorName == "text1") gout << color(Text1ColorR, Text1ColorG, Text1ColorB);
    else if(ColorName == "text2") gout << color(Text2ColorR, Text2ColorG, Text2ColorB);
    else gout << color(255,255,255);
}

void Widget::WriteTextAlignLeft(string value)
{
        gout
        << move_to(coord_x + 1, coord_y+(size_y/2)+ gout.cdescent())
        << text(value);
}

void Widget::WriteTextAlignRight(string value)
{
        gout
        << move_to(coord_x + size_x - gout.twidth(value), coord_y+(size_y/2)+ gout.cdescent())
        << text(value);
}

void Widget::WriteTextAlignCenter(string value)
{
        gout
        << move_to(coord_x + (size_x -gout.twidth(value))/2, coord_y+(size_y/2)+ gout.cdescent())
        << text(value);
}

void Widget::Load(Application* ap)
{
    ap->LoadWidget(this);
}
