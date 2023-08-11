//
// Created by haruspex on 10.08.23.
//

#ifndef LEARN_SDL_ENEMY_H
#define LEARN_SDL_ENEMY_H

#include "GameObject.h"

class Enemy : public GameObject {
public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean() { std::cout << "clean game object"; }
};


#endif //LEARN_SDL_ENEMY_H
