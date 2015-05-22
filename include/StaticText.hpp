#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED
#include "Widget.hpp"
#include <string>

class StaticText : public Widget
{
protected:
    std::string value;
    std::string align;
    std::string color;
public:
    StaticText(Application* ap, int x, int y, int sx, int sy, std::string txt, std::string al, std::string col);
    virtual void Draw();
    void SetValue(std::string txt);
    std::string GetValue();
};



#endif // STATICTEXT_HPP_INCLUDED
