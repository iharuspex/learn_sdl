#ifndef LEARN_SDL_GAMEOBJECT_H
#define LEARN_SDL_GAMEOBJECT_H

#include <iostream>
#include <SDL.h>

#include "LoaderParams.h"

class GameObject {
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;

protected:
    explicit GameObject(const LoaderParams* pParams) {};
    virtual ~GameObject() = default;
};

#endif //LEARN_SDL_GAMEOBJECT_H
