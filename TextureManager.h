#ifndef LEARN_SDL_TEXTUREMANAGER_H
#define LEARN_SDL_TEXTUREMANAGER_H

#include <string>
#include <map>

#include <SDL.h>

class TextureManager {
public:
    static TextureManager* instance();

    ~TextureManager();

    bool load(const std::string& fileName, const std::string& id, SDL_Renderer* pRenderer);

    void draw(const std::string& id, int x, int y, int width, int height, SDL_Renderer* pRenderer,
              SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,
                   SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
    TextureManager();

    std::map<std::string, SDL_Texture*> m_textureMap;
};

typedef TextureManager TheTextureManager;

#endif //LEARN_SDL_TEXTUREMANAGER_H
