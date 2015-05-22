#include "Sudoku_Mezo.hpp"

SudokuMezo::SudokuMezo(int v, bool g)
    : Value(v), Generated(g) {

    WrongBox = false;
    WrongRow = false;
    WrongColumn = false;
    WrongNull = false;
    }

