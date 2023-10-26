add_library(game src/game.cpp)

add_executable(game_test test/game_test.cpp)
target_link_libraries( game_test PRIVATE doctest game)
add_test(game_test game_test)

target_include_directories(game PUBLIC include)