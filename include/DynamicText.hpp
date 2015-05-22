#ifndef DYNAMICTEXT_HPP_INCLUDED
#define DYNAMICTEXT_HPP_INCLUDED
#include "widget.hpp"
#include <string>

class DynamicText : public Widget
{
protected:
    std::string value;
public:
    DynamicText(Application* ap, int x, int y, int sx, int sy, std::string value);
    virtual void Draw();
    virtual void EventHandler(genv::event ev);
    void Typing();
    void SetValue(std::string txt);
    std::string GetValue();
};


#endif // DYNAMICTEXT_HPP_INCLUDED
