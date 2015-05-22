#include "AmobaWidget.hpp"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
using namespace genv;



AmobaWidget::AmobaWidget(Application *ap, int x, int y, int sx, int sy, GameMod *gm, std::vector<std::vector<AmobaMezo> > v)
    : Widget(ap,x,y,sx,sy), GM(gm), AmobaMezoVector(v)
    {
    focusable = true;
    focused = false;
    Widget::Load(ap);
    }

void AmobaWidget::Draw()
{

    gout << move_to(coord_x, coord_y);
    for(unsigned i=0; i < AmobaMezoVector.size(); i++)
    {
        for(unsigned j=0; j < AmobaMezoVector.size(); j++)
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

void AmobaWidget::EventHandler(event ev)
{
    if(ev.button == btn_left)
    {

        for(unsigned i=0; i < AmobaMezoVector.size(); i++)
        {
            for(unsigned j=0; j < AmobaMezoVector.size(); j++)
            {
                if(ev.pos_x >= (i*size_x) + i && ev.pos_x < ((i+1)*size_x) + i && ev.pos_y >= (j*size_y) + j && ev.pos_y < ((j+1)*size_y) + j)
                {
                    GM -> FeedBackClick(i, j);
                }
            }
        }
    }
}

bool AmobaWidget::GetOnMe(int x, int y)
{
    if (x >=  coord_x && x < coord_x + (size_x * AmobaMezoVector.size()) && y >= coord_y && y < coord_y+(size_y * AmobaMezoVector.size())) return true;
    else return false;
}

void AmobaWidget::SetAmobaMezoVector(std::vector<std::vector<AmobaMezo> > v)
{
    AmobaMezoVector = v;
}
