#include "SudokuWidget.hpp"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
using namespace genv;



SudokuWidget::SudokuWidget(Application *ap, int x, int y, int sx, int sy, GameMod *gm, std::vector<std::vector<SudokuMezo> > v)
    : Widget(ap,x,y,sx,sy), GM(gm), SudokuMezoVector(v)
    {
    focusable = true;
    focused = false;
    Widget::Load(ap);
    }

void SudokuWidget::Draw()
{

    gout << move_to(coord_x, coord_y);
    for(unsigned i=0; i < SudokuMezoVector.size(); i++)
    {
        for(unsigned j=0; j < SudokuMezoVector.size(); j++)
        {
            stringstream ss;
            string temp;
            if(SudokuMezoVector[i][j].Value != 0)
            {
                ss << SudokuMezoVector[i][j].Value;
                ss >> temp;
            }
            else temp = "";

            gout << genv::move_to(coord_x + i*size_x + (i), coord_y + j*size_y + (j));
            if(SudokuMezoVector[i][j].Generated)
            {
                gout << color(200,200,200);
                gout << box(size_x, size_y);
            }
            else if(SudokuMezoVector[i][j].WrongBox || SudokuMezoVector[i][j].WrongRow || SudokuMezoVector[i][j].WrongColumn || SudokuMezoVector[i][j].WrongNull)
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

void SudokuWidget::EventHandler(event ev)
{
    if(ev.button == btn_left)
    {

        for(unsigned i=0; i < SudokuMezoVector.size(); i++)
        {
            for(unsigned j=0; j < SudokuMezoVector.size(); j++)
            {
                if(ev.pos_x >= (i*size_x) + i && ev.pos_x < ((i+1)*size_x) + i && ev.pos_y >= (j*size_y) + j && ev.pos_y < ((j+1)*size_y) + j)
                {
                    GM -> FeedBackClick(i, j);
                }
            }
        }
    }
}

bool SudokuWidget::GetOnMe(int x, int y)
{
    if (x >=  coord_x && x < coord_x + (size_x * SudokuMezoVector.size()) && y >= coord_y && y < coord_y+(size_y * SudokuMezoVector.size())) return true;
    else return false;
}

void SudokuWidget::SetSudokuMezoVector(std::vector<std::vector<SudokuMezo> > v)
{
    SudokuMezoVector = v;
}
