#pragma once
#include <vector>

class Game
{
private:
    std::vector<int> bowls;
    int rollNum;
public:
    Game();
    void roll(int pins);
    int score();
    bool strike(int index);
    bool split(int index);
    void print();
};