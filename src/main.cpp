#include <iostream>

#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[]) {
    Uint32 frameStart, frameTime;

    std::cout << "game init attempt...\n";

    if (TheGame::instance()->init("Chapter 1: Setting up SDL", 100, 100, 640, 480, false)) {
        std::cout << "game init success!\n";
        while (TheGame::instance()->isRunning()) {
            frameStart = SDL_GetTicks();

            TheGame::instance()->handleEvents();
            TheGame::instance()->update();
            TheGame::instance()->render();

            frameTime = SDL_GetTicks() - frameStart;

            if (frameTime < DELAY_TIME) {
                SDL_Delay((int) (DELAY_TIME - frameTime));
            }
        }
    } else {
        std::cout << "game init failure - " << SDL_GetError() << "\n";
        return EXIT_FAILURE;
    }

    std::cout << "game closing...\n";
    TheGame::instance()->clean();
    return EXIT_SUCCESS;
}
