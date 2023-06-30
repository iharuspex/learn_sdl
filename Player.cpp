//
// Created by haruspex on 30.06.23.
//

#include "Player.h"

#include <utility>

void Player::load(int x, int y, int width, int height, std::string textureID) {
    GameObject::load(x, y, width, height, std::move(textureID));
}

void Player::draw(SDL_Renderer *pRenderer) {
    GameObject::draw(pRenderer);
}

void Player::update() {
    m_x -= 1;
}
