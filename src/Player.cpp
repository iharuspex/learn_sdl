//
// Created by haruspex on 30.06.23.
//

#include "Player.h"

#include <utility>

Player::Player(const LoaderParams *pParams) : SDLGameObject(pParams) {

}

void Player::draw() {
    SDLGameObject::draw();
}

void Player::update() {
    m_x -= 1;
}

void Player::clean() {
    SDLGameObject::clean();
    std::cout << "clean player";
}


