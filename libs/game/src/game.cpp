#include <game.h>
#include <iostream>

Game::Game() : x(0) {
}

void Game::calculateBonus(int pins) {
    for (int i = 0; i < bonus.size(); i++) {
        if (bonus[i] != 0) {
            bonus[i]--;
            frames[i] += pins;
        }
    }
}

void Game::roll(int pins) {
    calculateBonus(pins);
    if (duo.empty()) {
        if (pins == 10) {
            frames.push_back(10);
            bonus.push_back(2);
        }
        else {
            duo.push_back(pins);
        }
    }
    else {
        frames.push_back(pins + duo.back());
        duo = {};
        if (frames.back() == 10) {
            bonus.push_back(1);
        }
        else {
            bonus.push_back(0);
        }
    }
}

int Game::score() {
    int sum = 0;
    for (int i = 0; i < bonus.size(); i++) {
        if (bonus[i] == 0) {
            sum += frames[i];
        }
        else {
            return sum;
        }
    }
    return sum;
}