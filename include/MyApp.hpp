#ifndef MYAPP_HPP_INCLUDED
#define MYAPP_HPP_INCLUDED
#include "Widget.hpp"
#include "StaticText.hpp"
#include "DynamicText.hpp"
#include "Button.hpp"
#include "SudokuWidget.hpp"
#include "Application.hpp"
#include "GameMod.hpp"
#include "Sudoku_Mezo.hpp"
#include  <vector>

class MyApp : public Application
{
protected:
    /*** CREATING WIDGET POINTERS ***/
    SudokuWidget *aw;
    Button *bt1;
    Button *bt2;
    StaticText *st1;
    StaticText *st2;
    StaticText *st3;
    StaticText *st4;
    StaticText *st5;
    StaticText *st6;
    /*** MYAPP VARIABLES***/
    GameMod *GM;
    std::vector<std::vector<SudokuMezo> > SudokuMezoVector;
public:
    MyApp(int w, int h);
    void Show();
    void GenerateSudokuMezoVector();

};

#endif // MYAPP_HPP_INCLUDED
