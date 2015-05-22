#include "GameMod.hpp"
#include <iostream>

using namespace std;

GameMod::GameMod(std::vector<std::vector<AmobaMezo> > v)
    : AmobaMezoVector(v) {}

void GameMod::FeedBackClick(int x, int y)
{
    IncValue(x,y);
}

void GameMod::IncValue(int x, int y)
{
    if(AmobaMezoVector[x][y].Value < 9)  AmobaMezoVector[x][y].Value++;
    else  AmobaMezoVector[x][y].Value = 0;
}

std::vector<std::vector<AmobaMezo> > GameMod::GetAmobaMezoVector()
{
    return AmobaMezoVector;
}
