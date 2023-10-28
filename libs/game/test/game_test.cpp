#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <game.h>
#include "doctest/doctest.h"
using namespace std;

TEST_CASE("Test basics") {
    Game* game = new Game();

    CHECK(game->score() == 0);

    game->roll(2);
    CHECK(game->score() == 2);

    game->roll(6);
    CHECK(game->score() == 8);

    game->roll(2);
    CHECK(game->score() == 10); 

    game->roll(4);
    CHECK(game->score() == 14); 
}

TEST_CASE("Test with bonus points") {
    Game *game = new Game();

    game->roll(2);
    CHECK(game->score() == 2);
    game->roll(6);
    CHECK(game->score() == 8);
    game->roll(2);
    CHECK(game->score() == 10);
    game->roll(4);
    CHECK(game->score() == 14);
    game->roll(10);
    CHECK(game->score() == 24);
    game->roll(10);
    CHECK(game->score() == 44);
    game->roll(6);
    CHECK(game->score() == 62);
    game->roll(3);
    CHECK(game->score() == 68);

    game->rollMany(2, 1);
    CHECK(game->score() == 70);

    game->roll(10);
    CHECK(game->score() == 80);
    game->roll(10);
    CHECK(game->score() == 100);
    game->roll(10);
    CHECK(game->score() == 130);
    game->roll(10);
    CHECK(game->score() == 160);
    game->roll(10);
    CHECK(game->score() == 180);
    game->roll(10);
    CHECK(game->score() == 190);
}

TEST_CASE("Perfect game") {
    Game* game = new Game();
    game->rollMany(10, 12);
    CHECK(game->score() == 300);
}

TEST_CASE("Game with no points") {
    Game* game = new Game();
    game->rollMany(10, 0);
    CHECK(game->score() == 0);
}

