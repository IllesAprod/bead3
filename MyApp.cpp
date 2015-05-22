#include "MyApp.hpp"
#include <iostream>
#include "graphics.hpp"
using namespace std;
using namespace genv;

MyApp::MyApp(int w, int h)
: Application(w,h)
{
 st1 = new DynamicText(this, 100, 100, 100, 20, "valami1");
 st1 = new DynamicText(this, 100, 130, 100, 20, "valami2");
 st1 = new DynamicText(this, 100, 160, 100, 20, "valami3");
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
