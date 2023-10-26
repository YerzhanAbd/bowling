#include <game.h>
#include <iostream>

Game::Game() : x(0) {
}

void Game::roll(int pins) {
    if (duo.empty()) {
        if (pins == 10) {
            frames.push_back(10);
        }
        else {
            duo.push_back(pins);
        }
    }
    else {
        frames.push_back(pins + duo.back());
        duo = {};
    }
}

int Game::score() {
    int sum = 0;
    for (auto frame: frames) {
        sum += frame;
    }
    return sum;
}