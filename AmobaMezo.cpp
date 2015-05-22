#include "AmobaWidget.hpp"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
using namespace genv;



AmobaWidget::AmobaWidget(Application *ap, int x, int y, int sx, int sy, std::vector<std::vector<AmobaMezo> > v)
    : Widget(ap,x,y,sx,sy),  AmobaMezoVector(v)
    {
    Widget::Load(ap);
    }

void AmobaWidget::Draw()
{


    gout << move_to(coord_x, coord_y);
    for(unsigned i=0; i < 9; i++)
    {
        for(unsigned j=0; j < 9; j++)
        {
            stringstream ss;
            string temp;
            ss << AmobaMezoVector[i][j].Value;
            ss >> temp;
            gout << genv::move_to(coord_x + i*size_x + (i), coord_y + j*size_y + (j));
            if(AmobaMezoVector[i][j].Generated)
            {
                gout << color(200,200,200);
                gout << box(size_x, size_y);
            }
            else if(AmobaMezoVector[i][j].WrongValue)
            {
                gout << color(255,0,0);
                gout << box(size_x, size_y);
            }
            else
            {
                gout << color(255,255,255);
                gout << box(size_x, size_y);
            }
            gout << genv::move_to(coord_x + i*size_x + (i) + (size_x - gout.twidth(temp))/2, coord_y + j*size_y + (j) + (size_y/2)+ gout.cdescent()) << color(0,0,0) << text(temp);

        }
    }
}
