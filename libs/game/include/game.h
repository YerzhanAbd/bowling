#pragma once
#include <vector>

class Game
{
private:
    int x;
    std::vector<int> duo;
    std::vector<int> frames;
    std::vector<int> bonus;
public:
    Game();
    void roll(int pins);
    int score();
};