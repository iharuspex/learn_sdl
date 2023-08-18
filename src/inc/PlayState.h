#ifndef LEARN_SDL_PLAYSTATE_H
#define LEARN_SDL_PLAYSTATE_H

#include <vector>

#include "GameState.h"
#include "GameObject.h"

class GameObject;

class PlayState : public GameState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    [[nodiscard]] virtual std::string getStateID() const;

private:
    static const std::string s_playID;

    std::vector<GameObject*> m_gameObjects;
};


#endif //LEARN_SDL_PLAYSTATE_H
