#ifndef AMOBAWIDGET_HPP_INCLUDED
#define AMOBAWIDGET_HPP_INCLUDED
#include <vector>
#include "Widget.hpp"
#include "GameMod.hpp"
#include "Amoba_Mezo.hpp"

class GameMod;

class AmobaWidget : public Widget{
protected:
    GameMod *GM;
    std::vector<std::vector<AmobaMezo> > AmobaMezoVector;
public:
    AmobaWidget(Application* ap, int x, int y, int sx, int sy, GameMod *gm, std::vector<std::vector<AmobaMezo> > v);
    virtual void Draw();
    virtual void EventHandler(genv::event ev);
    virtual bool GetOnMe(int x, int y);
    void SetAmobaMezoVector(std::vector<std::vector<AmobaMezo> > v);
};

#endif // AMOBAWIDGET_HPP_INCLUDED
