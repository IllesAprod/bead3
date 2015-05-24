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
 aw = new SudokuWidget(this, 400,50,40,40, GM, SudokuMezoVector);
 bt1 = new Button(this, 20, 300, 200, 50, "GENERATE", [&](){

                 GM -> GenerateSudoku();

                 });
 bt1 = new Button(this, 20, 380, 200, 50, "SOLVE", [&](){

                 GM -> SetBackGenerated();
                 GM -> SolveSudoku();

                 });

st1 = new StaticText(this, 0,50,200,20, "Sudoku - Illes Aprod", "center", "Text1");
st2 = new StaticText(this, 10, 80, 200, 20, "A szamok noveleshez kattintson rajuk!", "left", "Text2");
st3 = new StaticText(this, 10, 100, 200, 20, "Ha valamelyik sorban / oszlopban / 3x3-as ", "left", "Text2");
st4 = new StaticText(this, 10, 120, 200, 20, "negyzetben hiba van, akkor pirosra valtozik.", "left", "Text2");
st5 = new StaticText(this, 10, 140, 200, 20, "A szurke negyzetek elore megadottak es", "left", "Text2");
st6 = new StaticText(this, 10, 160, 200, 20, "nem valtoztathatoak! Jo jatekot!", "left", "Text2");



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

