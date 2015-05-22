#ifndef Sudoku_MEZO_HPP_INCLUDED
#define Sudoku_MEZO_HPP_INCLUDED

class SudokuMezo {

public:
    int Value;
    bool Generated;
    bool WrongBox;
    bool WrongRow;
    bool WrongColumn;
    bool WrongNull;

    SudokuMezo (int v, bool g);

};

#endif // Sudoku_MEZO_HPP_INCLUDED
