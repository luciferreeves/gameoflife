#include <SDL2/SDL.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include "constants.h"

// Game Screen Class -> Uses SDL2
class GameScreen {
    SDL_Window *window{};
    SDL_Renderer *renderer{};
    SDL_bool done;
    std::vector<SDL_FPoint> points;
    std::vector<SDL_Color> colors;
    SDL_Event event{};

public:
    GameScreen() {
        SDL_Init(SDL_INIT_VIDEO);
        SDL_CreateWindowAndRenderer(SCREEN_WIDTH * SCALE_FACTOR,
                                    SCREEN_HEIGHT * SCALE_FACTOR,
                                    0, &window, &renderer);
        SDL_SetWindowTitle(window, "Game of Life");
        SDL_RenderSetScale(renderer, SCALE_FACTOR, SCALE_FACTOR);
        done = SDL_FALSE;
    }

    void drawPixel(double xm, double ym, uint8_t r = 255, uint8_t g = 255, uint8_t b = 255, uint8_t a = 255) {
        points.push_back({static_cast<float>(xm), static_cast<float>(ym)});
        colors.push_back({r, g, b, a});
    }

    void clearPixels() {
        points.clear();
    }

    void update() {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (long unsigned int i = 0; i < points.size(); ++i) {
            SDL_SetRenderDrawColor(renderer, colors[i].r, colors[i].g, colors[i].b, colors[i].a);
            SDL_RenderDrawPointF(renderer, points[i].x, points[i].y);
        }

        SDL_RenderPresent(renderer);
    }

    void input() {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    done = SDL_TRUE;
                    SDL_Quit();
                    exit(0);
                    break;
                default:
                    break;
            }
        }
    }
};
