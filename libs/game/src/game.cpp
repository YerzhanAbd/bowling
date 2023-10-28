#include <game.h>
#include <iostream>
#include <numeric>

Game::Game() : rollNum(0), bowls(21, 0) {
}

bool Game::strike(int index) {
    return bowls[index] == 10;
}

bool Game::split(int index) {
    return bowls[index] + bowls[index+1] == 10;
}

void Game::roll(int pins) {
    bowls[rollNum] = pins;
    rollNum++;
}

void Game::rollMany(int rolls, int pins) {
    for (int i = 0; i < rolls; i++) {
        roll(pins);
    }
}

void Game::print() {
    for (auto bowl: bowls) {
        std::cout << bowl << ' ';
    }
    std::cout << std::endl;
}

int Game::score() {
    int sum = 0;
    if (bowls.size() == 0) {
        return 0;
    }

    int index = 0;
    for (int i = 0; i < 10; i++) {
        if (strike(index)) {
            sum += 10 + bowls[index+1] + bowls[index+2];
            index += 1;
        }                 
        else if (split(index)) {
            sum += bowls[index] + bowls[index+1] + bowls[index+2]; 
            index += 2;
        }
        else {
            sum += bowls[index] + bowls[index+1];
            index += 2;
        }
    }
    return sum; 
}