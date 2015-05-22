#ifndef GAMEMOD_HPP_INCLUDED
#define GAMEMOD_HPP_INCLUDED
#include "Sudoku_Mezo.hpp"
#include <vector>

class GameMod {
protected:
    std::vector<std::vector<SudokuMezo> > SudokuMezoVector;
public:
    GameMod(std::vector<std::vector<SudokuMezo> > v);
    void FeedBackClick(int x, int y);
    void IncValue(int x, int y);
    std::vector<std::vector<SudokuMezo> > GetSudokuMezoVector();
};

#endif // GAMEMOD_HPP_INCLUDED
