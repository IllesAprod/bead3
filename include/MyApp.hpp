#ifndef MYAPP_HPP_INCLUDED
#define MYAPP_HPP_INCLUDED
#include "Widget.hpp"
#include "StaticText.hpp"
#include "DynamicText.hpp"
#include "AmobaWidget.hpp"
#include "Application.hpp"
#include "GameMod.hpp"
#include "Amoba_Mezo.hpp"
#include  <vector>

class MyApp : public Application
{
protected:
    /*** CREATING WIDGET POINTERS ***/
    DynamicText *st1;
    DynamicText *st2;
    DynamicText *st3;
    AmobaWidget *aw;
    /*** MYAPP VARIABLES***/
    GameMod *GM;
    std::vector<std::vector<AmobaMezo> > AmobaMezoVector;
public:
    MyApp(int w, int h);
    void Show();
    void GenerateAmobaMezoVector();

};

#endif // MYAPP_HPP_INCLUDED
