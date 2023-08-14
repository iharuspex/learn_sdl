//
// Created by haruspex on 30.06.23.
//

#ifndef LEARN_SDL_PLAYER_H
#define LEARN_SDL_PLAYER_H

#include "SDLGameObject.h"

class Player : public SDLGameObject {
public:
    Player(const LoaderParams* pParams);

    virtual void draw();

    virtual void update();

    virtual void clean();
};


#endif //LEARN_SDL_PLAYER_H
