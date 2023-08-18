#include "Player.h"

#include "InputHandler.h"

Player::Player(const LoaderParams *pParams) : SDLGameObject(pParams) {

}

void Player::draw() {
    SDLGameObject::draw();
}

void Player::update() {
    m_currentFrame = int (((SDL_GetTicks() / 100)) % 6);

    Vector2D* target = TheInputHandler::instance()->getMousePosition();
    m_velocity = *target - m_position;
    m_velocity /= 50;

    SDLGameObject::update();
}

void Player::clean() {
    SDLGameObject::clean();
    std::cout << "clean player";
}


