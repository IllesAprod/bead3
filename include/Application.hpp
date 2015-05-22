#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"
#include <vector>

class Application
{
protected:
    genv::event ev;
    int width, height;
    std::vector<Widget *> Widgets;
    std::vector<Widget *> FocusableWidgets;
    unsigned int FocusIndex;
public:
    Application(int w, int h);
    void Initialize(); //???
    void LoadWidget(Widget* widget);
    void ClearScreen();

    /*** EVENT HANDLING***/
    void EventHandler();
    void KeyTab();
    void LeftClick(int x, int y);


};



#endif // APPLICATION_HPP_INCLUDED
