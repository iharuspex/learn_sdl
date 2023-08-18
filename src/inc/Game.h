#ifndef LEARN_SDL_GAME_H
#define LEARN_SDL_GAME_H

#include <SDL.h>
#include <vector>

#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"
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

    void quit();

    SDL_Renderer* getRenderer() const;
    GameStateMachine* getStateMachine();

private:
    Game();

    static Game* s_pInstance;

    SDL_Window* m_pWindow = nullptr;
    SDL_Renderer* m_pRenderer = nullptr;

    int m_currentFrame;

    bool m_bRunning = false;

    GameStateMachine* m_pGameStateMachine;

    std::vector<SDLGameObject*> m_gameObjects;
};

typedef Game TheGame;

#endif //LEARN_SDL_GAME_H
