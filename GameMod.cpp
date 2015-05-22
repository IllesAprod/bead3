#include "GameMod.hpp"
#include <iostream>

using namespace std;

GameMod::GameMod(std::vector<std::vector<SudokuMezo> > v)
    : SudokuMezoVector(v) {}

void GameMod::FeedBackClick(int x, int y)
{
    IncValue(x,y);
}

void GameMod::IncValue(int x, int y)
{
    if(SudokuMezoVector[x][y].Value < 9)  SudokuMezoVector[x][y].Value++;
    else  SudokuMezoVector[x][y].Value = 0;
}

std::vector<std::vector<SudokuMezo> > GameMod::GetSudokuMezoVector()
{
    return SudokuMezoVector;
}
