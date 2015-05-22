#include "ListDropDown.hpp"
#include <stdlib.h>

using namespace std;
using namespace genv;

ListDropDown::ListDropDown()(Application* ap, int x, int y, int sx, int sy, int moi)
    : Widget(ap,x,y,sx,sy)
    {
        focusable = true;
        focused = false;
        open = false;
        visible_index = 0;
        Grip_Position = 1;
        max_open_item = moi;

        Content_Size = Items.size() * size_y;
        Window_Size = max_open_item * size_y;
        Grip_Size = (Window_Size / Content_Size) * Window_Size;

        if(max_open_item >= Items.size()) scrollable = false;
        else scrollable = true;
    }

    void ListDropDown::Draw()
    {
        //VISIBLE TEXT

        string visible;

        if(Items.size() == 0)
        {
            visible = "";
        }
        else visible = Items[visible_index];

        //HEADER

        SetColor("border");
        DrawBorder();
        gout << move_to(coord_x + size_x - 25, coord_y) << line(0, size_y)
        <<  move_to (coord_x + size_x - 20, coord_y + (size_y / 3))
        << line(15, 0) << line(-(15/2), size_y-2*(size_y/3))
        << line_to(coord_x + size_x - 20, coord_y + (size_y / 3))
        << move_to(coord_x, coord_y);

        WriteTextAlignLeft(visible);

        if(!open)
        {

        }
        else if(open && !scrollable)
        {

        }
        else if(open && scrollable)
        {

        }
    }
