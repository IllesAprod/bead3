#ifndef AMOBAWIDGET_HPP_INCLUDED
#define AMOBAWIDGET_HPP_INCLUDED
#include <vector>
#include "Widget.hpp"
#include "Amoba_Mezo.hpp"

class AmobaWidget : public Widget{
protected:
   std::vector<std::vector<AmobaMezo> > AmobaMezoVector;
public:
    AmobaWidget(Application* ap, int x, int y, int sx, int sy, std::vector<std::vector<AmobaMezo> > v);
    virtual void Draw();
};

#endif // AMOBAWIDGET_HPP_INCLUDED
