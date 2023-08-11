#include <iostream>

#include "Game.h"

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

    if (!TheTextureManager::instance()->load("../assets/PrototypeHero_noSword.png", "animate", m_pRenderer)) {
        return false;
    }

    m_go = new GameObject();
    m_player = new Player();
    m_enemy = new Enemy();

    m_go->load(100, 100, 100, 80, "animate");
    m_player->load(300, 300, 100, 80, "animate");
    m_enemy->load(0, 0, 100, 80, "animate");

    m_gameObjects.push_back(m_go);
    m_gameObjects.push_back(m_player);
    m_gameObjects.push_back(m_enemy);

    std::cout << "Init success\n";
    m_bRunning = true;

    return true;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);

    for (auto & m_gameObject : m_gameObjects) {
        m_gameObject->draw(m_pRenderer);
    }

    SDL_RenderPresent(m_pRenderer);
}

void Game::clean() {
    std::cout << "Cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
                break;
        }
    }
}

void Game::update() {
    for (auto & m_gameObject : m_gameObjects) {
        m_gameObject->update();
    }
}

bool Game::isRunning() {
    return m_bRunning;
}
