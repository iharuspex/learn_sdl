#ifndef LEARN_SDL_GAMESTATEMACHINE_H
#define LEARN_SDL_GAMESTATEMACHINE_H

#include <vector>

#include "GameState.h"

class GameStateMachine {
public:
    void update();
    void render();

    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();

private:
    std::vector<GameState*> m_gameStates;
};


#endif //LEARN_SDL_GAMESTATEMACHINE_H
