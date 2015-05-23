#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include "Widget.hpp"
#include <string>
#include <functional>

class Button : public Widget {
protected:
    std::function<void()>fv;
    std::string value;
    bool pushed;

public:
    Button(Application *ap, int x, int y, int sx, int sy, std::string val, std::function<void()> f);
    virtual void Draw();
    virtual void EventHandler(genv::event ev);

};

#endif // BUTTON_HPP_INCLUDED
