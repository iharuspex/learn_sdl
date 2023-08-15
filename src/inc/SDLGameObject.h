//
// Created by haruspex on 14.08.23.
//

#ifndef LEARN_SDL_SDLGAMEOBJECT_H
#define LEARN_SDL_SDLGAMEOBJECT_H

#include "GameObject.h"

#include "Vector2D.h"

class SDLGameObject : public GameObject {
public:
    explicit SDLGameObject(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

protected:
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;

    int m_width;
    int m_height;

    int m_currentRow;
    int m_currentFrame;

    std::string m_textureID;
};


#endif //LEARN_SDL_SDLGAMEOBJECT_H
