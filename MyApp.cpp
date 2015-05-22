#include "MyApp.hpp"
#include <iostream>
#include "graphics.hpp"
#include "stdlib.h"
using namespace std;
using namespace genv;

MyApp::MyApp(int w, int h)
: Application(w,h)
{
GenerateAmobaMezoVector();

 //st1 = new DynamicText(this, 100, 100, 100, 20, "valami1");
 //st1 = new DynamicText(this, 100, 130, 100, 20, "valami2");
 //st1 = new DynamicText(this, 100, 160, 100, 20, "valami3");
 aw = new AmobaWidget(this, 0,0,40,40,AmobaMezoVector);
}

void MyApp::Show()
{
    while(gin >> ev) {
    ClearScreen();
    EventHandler();
    for (unsigned i = 0; i<Widgets.size(); i++)
        {
        Widgets[i] -> Draw();
        }
    gout << refresh;
    }
}

void MyApp::GenerateAmobaMezoVector()
{
    for(int i=0; i<9; i++)
    {
        vector<AmobaMezo> temp;
        for(int j=0; j<9; j++)
        {
            AmobaMezo m_temp(rand()%10, rand()%2);
            temp.push_back(m_temp);
        }
        AmobaMezoVector.push_back(temp);
    }
}
