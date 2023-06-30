#include "TextureManager.h"

#include "SDL_image.h"

TextureManager* s_pInstance = nullptr;

TextureManager::TextureManager() {

}

TextureManager::~TextureManager() {

}

TextureManager *TextureManager::instance() {
    if (s_pInstance == nullptr) {
        s_pInstance = new TextureManager();
        return s_pInstance;
    }

    return s_pInstance;
}

bool TextureManager::load(const std::string& fileName, const std::string& id, SDL_Renderer *pRenderer) {
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

    if (pTempSurface == nullptr) {
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    if (pTexture != nullptr) {
        m_textureMap[id] = pTexture;
        return true;
    }

    return false;
}

void TextureManager::draw(const std::string& id, int x, int y, int width, int height, SDL_Renderer *pRenderer,
                          SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = dstRect.w = width;
    srcRect.h = dstRect.h = height;
    dstRect.x = x;
    dstRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,
                               SDL_Renderer *pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = dstRect.w = width;
    srcRect.h = dstRect.h = height;
    dstRect.x = x;
    dstRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}
