//
// Created by haruspex on 28.06.23.
//

#ifndef LEARN_SDL_GAME_H
#define LEARN_SDL_GAME_H

#include <SDL.h>
#include <vector>

#include "TextureManager.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:
    static Game* instance();

    ~Game();

    bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool isRunning();

    SDL_Renderer* getRenderer() const;

private:
    Game();

    static Game* s_pInstance;

    SDL_Window* m_pWindow = nullptr;
    SDL_Renderer* m_pRenderer = nullptr;

    int m_currentFrame;

    bool m_bRunning = false;


    std::vector<SDLGameObject*> m_gameObjects;
};

typedef Game TheGame;

#endif //LEARN_SDL_GAME_H
