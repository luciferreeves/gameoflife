#include <array>
#include <random>
#include "screen.h"

using Array2D = std::array<std::array<int, SCREEN_HEIGHT>, SCREEN_WIDTH>;

// Two-dimensional array of ints
struct Game {
    Array2D display {};
    Array2D swap {};
};

// random number generator function:
int zeroOrOne() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    return dis(gen);
}

// function to check if the cell will be alive or dead in the next generation
bool isAlive(Array2D &game, int x, int y) {
    int alive = 0;

    // left test
    if (x > 0 && game[x - 1][y] == 1) alive++;
    // right test
    if (x < SCREEN_WIDTH && game[x + 1][y] == 1) alive++;
    // top test
    if (y > 0 && game[x][y - 1] == 1) alive++;
    // bottom test
    if (y < SCREEN_HEIGHT && game[x][y + 1] == 1) alive++;
    // top left test
    if (x > 0 && y > 0 && game[x - 1][y - 1] == 1) alive++;
    // top right test
    if (x < SCREEN_WIDTH && y > 0 && game[x + 1][y - 1] == 1) alive++;
    // bottom left test
    if (x > 0 && y < SCREEN_HEIGHT && game[x - 1][y + 1] == 1) alive++;
    // bottom right test
    if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT && game[x + 1][y + 1] == 1) alive++;

    // if the cell is alive and has 2 or 3 neighbors, it stays alive or
    // if the cell is dead and has exactly 3 neighbors, it comes to life
    if ((game[x][y] == 1 && (alive == 2 || alive == 3)) || (game[x][y] == 0 && alive == 3)) return true;
        // otherwise, the cell dies
    else return false;
}
