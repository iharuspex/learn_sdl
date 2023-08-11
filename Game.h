//
// Created by haruspex on 28.06.23.
//

#ifndef LEARN_SDL_GAME_H
#define LEARN_SDL_GAME_H

#include <SDL.h>
#include <vector>

#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:
    Game();
    ~Game();

    bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool isRunning();

private:
    SDL_Window* m_pWindow = nullptr;
    SDL_Renderer* m_pRenderer = nullptr;

    int m_currentFrame;

    bool m_bRunning = false;

    GameObject *m_go;
    GameObject *m_player;
    GameObject *m_enemy;

    std::vector<GameObject*> m_gameObjects;
};


#endif //LEARN_SDL_GAME_H
