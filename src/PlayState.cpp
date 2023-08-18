#include <iostream>

#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "PauseState.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
    if (TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        TheGame::instance()->getStateMachine()->pushState(new PauseState());
    }

    for (auto & m_gameObject : m_gameObjects) {
        m_gameObject->update();
    }
}

void PlayState::render() {
    for (auto & m_gameObject : m_gameObjects) {
        m_gameObject->draw();
    }
}

bool PlayState::onEnter() {
    if (!TheTextureManager::instance()->load("../assets/PrototypeHero_noSword.png", "hero",
                                             TheGame::instance()->getRenderer())) {
        return false;
    }

    GameObject* player = new Player(new LoaderParams(100, 100, 100, 80, "hero"));
    m_gameObjects.push_back(player);

    std::cout << "entering PlayState\n";
    return true;
}

bool PlayState::onExit() {
    for (auto & m_gameObject : m_gameObjects) {
        m_gameObject->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::instance()->clearFromTextureMap("hero");

    std::cout << "exiting PlayState\n";
    return true;
}

std::string PlayState::getStateID() const {
    return s_playID;
}
