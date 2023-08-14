#include <iostream>

#include "Game.h"

Game* g_game = nullptr;

int main(int argc, char* argv[]) {
    std::cout << "game init attempt...\n";

    if (TheGame::instance()->init("Chapter 1: Setting up SDL", 100, 100, 640, 480, false)) {
        std::cout << "game init success!\n";
        while (TheGame::instance()->isRunning()) {
            TheGame::instance()->handleEvents();
            TheGame::instance()->update();
            TheGame::instance()->render();

            SDL_Delay(10);
        }
    } else {
        std::cout << "game init failure - " << SDL_GetError() << "\n";
        return EXIT_FAILURE;
    }

    std::cout << "game closing...\n";
    TheGame::instance()->clean();
    return EXIT_SUCCESS;
}
