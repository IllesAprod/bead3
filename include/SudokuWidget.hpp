#ifndef SudokuWIDGET_HPP_INCLUDED
#define SudokuWIDGET_HPP_INCLUDED
#include <vector>
#include "Widget.hpp"
#include "GameMod.hpp"
#include "Sudoku_Mezo.hpp"

class GameMod;

class SudokuWidget : public Widget{
protected:
    GameMod *GM;
    std::vector<std::vector<SudokuMezo> > SudokuMezoVector;
public:
    SudokuWidget(Application* ap, int x, int y, int sx, int sy, GameMod *gm, std::vector<std::vector<SudokuMezo> > v);
    virtual void Draw();
    virtual void EventHandler(genv::event ev);
    virtual bool GetOnMe(int x, int y);
    void SetSudokuMezoVector(std::vector<std::vector<SudokuMezo> > v);
};

#endif // SudokuWIDGET_HPP_INCLUDED
