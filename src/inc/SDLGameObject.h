//
// Created by haruspex on 14.08.23.
//

#ifndef LEARN_SDL_SDLGAMEOBJECT_H
#define LEARN_SDL_SDLGAMEOBJECT_H

#include "GameObject.h"

class SDLGameObject : public GameObject {
public:
    SDLGameObject(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

protected:
    int m_x;
    int m_y;

    int m_width;
    int m_height;

    int m_currentRow;
    int m_currentFrame;

    std::string m_textureID;
};


#endif //LEARN_SDL_SDLGAMEOBJECT_H
