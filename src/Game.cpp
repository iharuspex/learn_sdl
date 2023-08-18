#include <iostream>

#include "Game.h"

#include "InputHandler.h"

Game* Game::s_pInstance = nullptr;

Game::Game() {

}

Game::~Game() {

}

bool Game::init(const char *title, int xpos, int ypos, int height, int width, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

        if (m_pWindow != nullptr) {
            std::cout << "Window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                std::cout << "Renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
            } else {
                std::cout << "Renderer init fail\n";
                return false;
            }
        } else {
            std::cout << "Window init fail\n";
            return false;
        }
    } else {
        std::cout << "SDL init fail\n";
        return false;
    }

    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MenuState());

    TheInputHandler::instance()->initialiseJoysticks();

    if (!TheTextureManager::instance()->load("../assets/PrototypeHero_noSword.png", "animate", m_pRenderer)) {
        return false;
    }

    m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 100, 80, "animate")));
    m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 100, 80, "animate")));

    std::cout << "Init success\n";
    m_bRunning = true;

    return true;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);

//    for (auto & m_gameObject : m_gameObjects) {
//        m_gameObject->draw();
//    }

    m_pGameStateMachine->render();

    SDL_RenderPresent(m_pRenderer);
}

void Game::clean() {
    std::cout << "Cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    TheInputHandler::instance()->clean();
    SDL_Quit();
}

void Game::handleEvents() {
    TheInputHandler::instance()->update();

    if (TheInputHandler::instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
        m_pGameStateMachine->changeState(new PlayState());
    }
}

void Game::update() {
//    for (auto & m_gameObject : m_gameObjects) {
//        m_gameObject->update();
//    }

    m_pGameStateMachine->update();
}

bool Game::isRunning() {
    return m_bRunning;
}

Game *Game::instance() {
    if (s_pInstance == nullptr) {
        s_pInstance = new Game();
    }
    return s_pInstance;
}

SDL_Renderer *Game::getRenderer() const {
    return m_pRenderer;
}

void Game::quit() {
    m_bRunning = false;
    SDL_Quit();
}

GameStateMachine *Game::getStateMachine() {
    return m_pGameStateMachine;
}
