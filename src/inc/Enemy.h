//
// Created by haruspex on 10.08.23.
//

#ifndef LEARN_SDL_ENEMY_H
#define LEARN_SDL_ENEMY_H

#include "SDLGameObject.h"

class Enemy : public SDLGameObject {
public:
    Enemy(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
};


#endif //LEARN_SDL_ENEMY_H
