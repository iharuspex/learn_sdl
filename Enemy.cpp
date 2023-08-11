//
// Created by haruspex on 10.08.23.
//

#include "Enemy.h"

void Enemy::update() {
    m_y += 1;
    m_x += 1;
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}