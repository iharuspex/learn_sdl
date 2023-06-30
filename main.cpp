#include <iostream>

#include "Game.h"

Game* g_game = nullptr;

int main(int argc, char* argv[]) {
    g_game = new Game();

    g_game->init("Chapter 1: Setting up SDL", 100, 100, 640, 480, false);

    while (g_game->isRunning()) {
        g_game->handleEvents();
        g_game->update();
        g_game->render();

        SDL_Delay(10);
    }

    g_game->clean();

    return EXIT_SUCCESS;
}
