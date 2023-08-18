#ifndef LEARN_SDL_MENUBUTTON_H
#define LEARN_SDL_MENUBUTTON_H

#include "SDLGameObject.h"

class MenuButton : public SDLGameObject {
public:
    explicit MenuButton(const LoaderParams* pParams, void (*callback)());

    virtual void draw();
    virtual void update();
    virtual void clean();

private:

    enum button_state {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        CLICKED
    };

    void (*m_callback)();

    bool m_bReleased;
};


#endif //LEARN_SDL_MENUBUTTON_H
