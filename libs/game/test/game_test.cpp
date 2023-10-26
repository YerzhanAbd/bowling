#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <game.h>
#include "doctest/doctest.h"
using namespace std;

TEST_CASE("Test basics") {
    Game* game = new Game();

    game->roll(2);
    CHECK(game->score() == 0);

    game->roll(6);
    CHECK(game->score() == 8);

    game->roll(2);
    CHECK(game->score() == 8); 

    game->roll(4);
    CHECK(game->score() == 14); 
}

TEST_CASE("Test with bonus points") {
    Game *game = new Game();

    game->roll(2);
    CHECK(game->score() == 0);
    game->roll(6);
    CHECK(game->score() == 8);
    game->roll(2);
    CHECK(game->score() == 8);
    game->roll(4);
    CHECK(game->score() == 14);
    game->roll(10);
    CHECK(game->score() == 14);
    game->roll(10);
    CHECK(game->score() == 14);
    game->roll(6);
    CHECK(game->score() == 40);
    game->roll(3);
    CHECK(game->score() == 68);

    game->roll(1);
    CHECK(game->score() == 68);
    game->roll(1);
    CHECK(game->score() == 70);

    game->roll(10);
    CHECK(game->score() == 70);
    game->roll(10);
    CHECK(game->score() == 70);
    game->roll(10);
    CHECK(game->score() == 100);

}

