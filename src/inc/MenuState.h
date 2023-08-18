#ifndef LEARN_SDL_MENUSTATE_H
#define LEARN_SDL_MENUSTATE_H

#include <vector>

#include "GameState.h"
#include "GameObject.h"

class MenuState : public GameState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    [[nodiscard]] virtual std::string getStateID() const;

private:
    static void s_menuToPlay();
    static void s_exitFromMenu();

    static const std::string s_menuID;

    std::vector<GameObject*> m_gameObjects;
};


#endif //LEARN_SDL_MENUSTATE_H
