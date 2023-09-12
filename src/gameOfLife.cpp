#include "game.h"

int main() {
    Game game;
    GameScreen screen;

    // create random points
    for (auto &row : game.display) {
        std::generate(row.begin(), row.end(), zeroOrOne);
    }

    // game loop
   for(;;) {
        // check for alive cells
        for (int i = 0; i < SCREEN_WIDTH; ++i) {
            for (int j = 0; j < SCREEN_HEIGHT; ++j) {
                // check if the cell will be alive or dead in the next generation
                game.swap[i][j] = isAlive(game.display, i, j) ? 1 : 0;
            }
        }

        // draw
        for (int i = 0; i < SCREEN_WIDTH; ++i) {
            for (int j = 0; j < SCREEN_HEIGHT; ++j) {
                if (game.swap[i][j] == 1) {
                    screen.drawPixel(i, j);
                }
            }
        }

        // swap buffers
        std::copy(game.swap.begin(), game.swap.end(), game.display.begin());

        // display to screen
        screen.update();
        SDL_Delay(20);
        screen.input();
        screen.clearPixels();
    }
}
