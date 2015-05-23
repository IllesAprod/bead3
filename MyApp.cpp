#include "MyApp.hpp"
#include <iostream>
#include "graphics.hpp"
#include "stdlib.h"
using namespace std;
using namespace genv;

MyApp::MyApp(int w, int h)
: Application(w,h)
{
GenerateSudokuMezoVector();

 //st1 = new DynamicText(this, 100, 100, 100, 20, "valami1");
 //st1 = new DynamicText(this, 100, 130, 100, 20, "valami2");
 //st1 = new DynamicText(this, 100, 160, 100, 20, "valami3");
 GM = new GameMod(SudokuMezoVector);
 aw = new SudokuWidget(this, 0,0,40,40, GM, SudokuMezoVector);
 bt1 = new Button(this, 20, 420, 100, 30, "GENERATE", [&](){

                 GM -> GenerateSudoku();

                 });
}

void MyApp::Show()
{
    while(gin >> ev) {
    ClearScreen();
    EventHandler();

    SudokuMezoVector = GM -> GetSudokuMezoVector();
    aw -> SetSudokuMezoVector(SudokuMezoVector);

    for (unsigned i = 0; i<Widgets.size(); i++)
        {
        Widgets[i] -> Draw();
        }

    gout << refresh;
    }
}

void MyApp::GenerateSudokuMezoVector()
{
    for(int i=0; i<9; i++)
    {
        vector<SudokuMezo> temp;
        for(int j=0; j<9; j++)
        {
            SudokuMezo m_temp(rand()%10, 0);
            temp.push_back(m_temp);
        }
        SudokuMezoVector.push_back(temp);
    }
}

