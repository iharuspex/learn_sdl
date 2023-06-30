//
// Created by haruspex on 30.06.23.
//

#ifndef LEARN_SDL_PLAYER_H
#define LEARN_SDL_PLAYER_H

#include "GameObject.h"

class Player : public GameObject {
public:
    void load(int x, int y, int width, int height, std::string textureID);

    void draw(SDL_Renderer* pRenderer);

    void update();

    void clean() {
        GameObject::clean();
        std::cout << "clean player";
    }
};


#endif //LEARN_SDL_PLAYER_H
