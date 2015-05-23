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
    DynamicText *st1;
    DynamicText *st2;
    DynamicText *st3;
    SudokuWidget *aw;
    Button *bt1;
    /*** MYAPP VARIABLES***/
    GameMod *GM;
    std::vector<std::vector<SudokuMezo> > SudokuMezoVector;
public:
    MyApp(int w, int h);
    void Show();
    void GenerateSudokuMezoVector();

};

#endif // MYAPP_HPP_INCLUDED
