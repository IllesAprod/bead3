#include "GameMod.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

GameMod::GameMod(std::vector<std::vector<SudokuMezo> > v)
    : SudokuMezoVector(v) {}

void GameMod::FeedBackClick(int x, int y)
{
    if(true /***!SudokuMezoVector[x][y].Generated***/) IncValue(x,y);
    CheckBoxes();
    CheckRows();
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

void GameMod::CheckAndSet0()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(SudokuMezoVector[i][j].Value == 0) SudokuMezoVector[i][j].WrongNull == true;
            else SudokuMezoVector[i][j].WrongNull == false;
        }
    }

}

void GameMod::CheckBoxes()
{
    for(int i=1; i<9; i += 3)
    {
        for(int j=1; j<9; j += 3)
        {
            if(CheckBox(i, j))
            {
                SetBoxWrongTrue(i, j);
            }
            else SetBoxWrongFalse(i, j);
        }
    }
}

bool GameMod::CheckBox(int x, int y)
{
    vector<int> temp;
    temp.push_back(SudokuMezoVector[x-1][y-1].Value);
    temp.push_back(SudokuMezoVector[x-1][y].Value);
    temp.push_back(SudokuMezoVector[x-1][y+1].Value);
    temp.push_back(SudokuMezoVector[x][y-1].Value);
    temp.push_back(SudokuMezoVector[x][y].Value);
    temp.push_back(SudokuMezoVector[x][y+1].Value);
    temp.push_back(SudokuMezoVector[x+1][y-1].Value);
    temp.push_back(SudokuMezoVector[x+1][y].Value);
    temp.push_back(SudokuMezoVector[x+1][y+1].Value);
    return CompareVector(temp);
}

void GameMod::SetBoxWrongTrue(int x, int y)
{
    SudokuMezoVector[x-1][y].WrongBox = true;    SudokuMezoVector[x-1][y-1].WrongBox = true;
    SudokuMezoVector[x-1][y+1].WrongBox = true;
    SudokuMezoVector[x][y-1].WrongBox = true;
    SudokuMezoVector[x][y].WrongBox = true;
    SudokuMezoVector[x][y+1].WrongBox = true;
    SudokuMezoVector[x+1][y-1].WrongBox = true;
    SudokuMezoVector[x+1][y].WrongBox = true;
    SudokuMezoVector[x+1][y+1].WrongBox = true;
}

void GameMod::SetBoxWrongFalse(int x, int y)
{
    SudokuMezoVector[x-1][y-1].WrongBox = false;
    SudokuMezoVector[x-1][y].WrongBox = false;
    SudokuMezoVector[x-1][y+1].WrongBox = false;
    SudokuMezoVector[x][y-1].WrongBox = false;
    SudokuMezoVector[x][y].WrongBox = false;
    SudokuMezoVector[x][y+1].WrongBox = false;
    SudokuMezoVector[x+1][y-1].WrongBox = false;
    SudokuMezoVector[x+1][y].WrongBox = false;
    SudokuMezoVector[x+1][y+1].WrongBox = false;
}

void GameMod::CheckRows()
{

    for(int i=0; i<9; i++)
    {
        if(CheckRow(i))
        {
            SetRowWrongTrue(i);
        }
        else SetRowWrongFalse(i);

    }
}

bool GameMod::CheckRow(int x)
{
    vector<int> temp;
    for(int j=0; j<9; j++)
    {
        temp.push_back(SudokuMezoVector[x][j].Value);
    }

return CompareVector(temp);
}

void GameMod::SetRowWrongTrue(int x)
{
    for(int j=0; j<9; j++)
    {
        SudokuMezoVector[x][j].WrongRow = true;
    }
}


void GameMod::SetRowWrongFalse(int x)
{
    for(int j=0; j<9; j++)
    {
        SudokuMezoVector[x][j].WrongRow = false;
    }
}

void GameMod::CheckColumns()
{
    for(int j=0; j<9; j++)
    {
        if(CheckColumn(j))
        {
            SetColumnWrongTrue(j);
        }
        else SetColumnWrongFalse(j);
    }
}

bool GameMod::CheckColumn(int y)
{
    vector<int> temp;
    for(int i=0; i<9; i++)
    {
        temp.push_back(SudokuMezoVector[i][y].Value);
    }

return CompareVector(temp);
}

void GameMod::SetColumnWrongTrue(int y)
{
    for(int i=0; i<9; i++)
    {
        SudokuMezoVector[i][y].WrongRow = true;
    }
}

void GameMod::SetColumnWrongFalse(int y)
{
    for(int i=0; i<9; i++)
    {
        SudokuMezoVector[i][y].WrongRow = false;
    }
}

bool GameMod::CompareVector(std::vector<int> v)
{
    vector<int> temp = v;

    for(unsigned i=0; i<v.size(); i++)
    {
        for(int j=0; j<temp.size(); j++)
        {
            if(v[i] == temp[j] && i != j)
            {
                return true;
            }

        }
    }

    return false;
}
