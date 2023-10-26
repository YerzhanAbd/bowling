#include <iostream>
#include <game.h>
using namespace std;

int main() {
    Game* game = new Game();
    game->roll(2);
    return 0;
}