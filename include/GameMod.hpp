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
    void CheckBoxes();
    void CheckRows();
    void CheckColumns();
    void CheckAndSet0();
    bool CheckBox(int x, int y);
    bool CheckRow(int x);
    bool CheckColumn(int y);
    bool CompareVector(std::vector<int> v);
    void SetBoxWrongTrue(int x, int y);
    void SetBoxWrongFalse(int x, int y);
    void SetRowWrongTrue(int x);
    void SetRowWrongFalse(int x);
    void SetColumnWrongTrue(int y);
    void SetColumnWrongFalse(int y);
    void GenerateSudoku();
    void LoadSudoku();
    bool Win();
    std::vector<std::vector<SudokuMezo> > GetSudokuMezoVector();
};

#endif // GAMEMOD_HPP_INCLUDED
