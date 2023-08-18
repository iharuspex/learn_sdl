#include <iostream>

#include "MenuState.h"
#include "MenuButton.h"
#include "TextureManager.h"
#include "Game.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
    for (auto & m_gameObject : m_gameObjects) {
        m_gameObject->update();
    }
}

void MenuState::render() {
    for (auto & m_gameObject : m_gameObjects) {
        m_gameObject->draw();
    }
}

bool MenuState::onEnter() {
    if (!TheTextureManager::instance()->load("../assets/menu/large_buttons/large_buttons/play_button.png",
                                             "playbutton", TheGame::instance()->getRenderer())) {
        return false;
    }

    if (!TheTextureManager::instance()->load("../assets/menu/large_buttons/large_buttons/exit_button.png",
                                             "exitbutton", TheGame::instance()->getRenderer())) {
        return false;
    }

    GameObject *button1 = new MenuButton(new LoaderParams(100, 100, 600, 200, "playbutton"), s_menuToPlay);
    GameObject *button2 = new MenuButton(new LoaderParams(100, 300, 600, 200, "exitbutton"), s_exitFromMenu);

    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    std::cout << "entering MenuState";

    return true;
}

bool MenuState::onExit() {
    for (auto & m_gameObject : m_gameObjects) {
        m_gameObject->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::instance()->clearFromTextureMap("playbutton");
    TheTextureManager::instance()->clearFromTextureMap("exitbutton");

    std::cout << "exiting MenuState\n";
    return true;
}

std::string MenuState::getStateID() const {
    return s_menuID;
}

void MenuState::s_menuToPlay() {
    std::cout << "Play button clicked\n";
    TheGame::instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu() {
    TheGame::instance()->quit();
}
