#ifndef DRAWFUNCTIONS_HPP_INCLUDED
#define DRAWFUNCTIONS_HPP_INCLUDED
#include "graphics.hpp"
#include <string>

using namespace std;

void DrawBorder(int coord_x, int coord_y, int size_x, int size_y)
{
    gout
    << move_to (coord_x, coord_y)
    << line(size_x, 0)
    << line(0, size_y)
    << line(-size_x, 0)
    << line(0, -size_y);
}


SetColor(string ColorName)
{
    string color_s;
    if(ColorName == "bg") gout << color(BgColorR, BgColorG, BgColorB);
    else if(ColorName == "border") gout << color(BorderColorR, BorderColorG, BorderColorB);
    else if(ColorName == "focus") gout << color(FocusColorR, FocusColorG, FocusColorB);
    else if(ColorName == "text1") gout << color(Text1ColorR, Text1ColorG, Text1ColorB);
    else if(ColorName == "text2") gout << color(Text2ColorR, Text2ColorG, Text2ColorB);
    else gout << color(255,255,255);
}

WritTextAlignLeft(string value)
{
        gout
        << move_to(coord_x + 1, coord_y+(size_y/2)+ gout.cdescent())
        << text(value);
}

WritTextAlignRight(string value)
{
        gout
        << move_to(coord_x + size_x - gout.twidth(value), coord_y+(size_y/2)+ gout.cdescent())
        << text(value);
}

WritTextAlignCenter(string value)
{
        gout
        << move_to(coord_x + (size_x -gout.twidth(value))/2, coord_y+(size_y/2)+ gout.cdescent())
        << text(value);
}


#endif // DRAWFUNCTIONS_HPP_INCLUDED
