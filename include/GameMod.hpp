#ifndef GAMEMOD_HPP_INCLUDED
#define GAMEMOD_HPP_INCLUDED
#include "Amoba_Mezo.hpp"
#include <vector>

class GameMod {
protected:
    std::vector<std::vector<AmobaMezo> > AmobaMezoVector;
public:
    GameMod(std::vector<std::vector<AmobaMezo> > v);
    void FeedBackClick(int x, int y);
    void IncValue(int x, int y);
    std::vector<std::vector<AmobaMezo> > GetAmobaMezoVector();
};

#endif // GAMEMOD_HPP_INCLUDED
