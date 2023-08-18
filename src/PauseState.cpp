#include "PauseState.h"
#include "Game.h"
#include "MenuButton.h"
#include "InputHandler.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain() {
    TheGame::instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay() {
    TheGame::instance()->getStateMachine()->popState();
}

void PauseState::update() {
    for (auto & m_gameObject : m_gameObjects) {
        m_gameObject->update();
    }
}

void PauseState::render() {
    for (auto & m_gameObject : m_gameObjects) {
        m_gameObject->draw();
    }
}

bool PauseState::onEnter() {
    if (!TheTextureManager::instance()->load("../assets/menu/large_buttons/large_buttons/continue_button.png",
                                             "resumebutton", TheGame::instance()->getRenderer())) {
        return false;
    }

    if (!TheTextureManager::instance()->load("../assets/menu/large_buttons/large_buttons/menu_button.png",
                                             "mainbutton", TheGame::instance()->getRenderer())) {
        return false;
    }

    GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 600, 200, "mainbutton"), s_pauseToMain);
    GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 600, 200, "resumebutton"), s_resumePlay);

    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    std::cout << "entering PauseState\n";

    return true;
}

bool PauseState::onExit() {
    for (auto & m_gameObject : m_gameObjects) {
        m_gameObject->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::instance()->clearFromTextureMap("resumebutton");
    TheTextureManager::instance()->clearFromTextureMap("mainbutton");
    TheInputHandler::instance()->reset();

    std::cout << "exiting PauseState\n";

    return true;
}

