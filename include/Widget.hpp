#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED
#include <string>
#include "graphics.hpp"

class Application;

class Widget{
protected:
    Application *AppPointer;
    int coord_x, coord_y, size_x, size_y;
    bool focusable, focused;
public:
    Widget (Application* ap, int x, int y, int sx, int sy);

    /*** GET FUNCTIONS ***/
    bool GetFocusable();
    bool GetFocused();
    virtual bool GetOnMe(int x, int y);

    /*** SET FUNCTIONS ***/
    void SetFocusOn();
    void SetFocusOff();

    /*** DRAW FUNCTIONS ***/
    virtual void Draw() {};
    void DrawFocused();
    void SetColor(std::string);
    void WriteTextAlignLeft(std::string);
    void WriteTextAlignCenter(std::string);
    void WriteTextAlignRight(std::string);
    void DrawBorder();
    void ClearScreen();

    /*** VIRTUAL FUNCTIONS ***/
    virtual void EventHandler(genv::event ev) {};

    void Load(Application* ap);

    /*** FEEDBACK ***/
    void FeedBackClick(int x, int y);

};




#endif // WIDGET_HPP_INCLUDED
