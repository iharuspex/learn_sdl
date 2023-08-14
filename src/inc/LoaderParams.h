#ifndef LEARN_SDL_LOADERPARAMS_H
#define LEARN_SDL_LOADERPARAMS_H

#include <string>

class LoaderParams {
public:
    LoaderParams(int x, int y, int width, int height, std::string textureID);

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    std::string getTextureID() const;

private:
    int m_x;
    int m_y;

    int m_width;
    int m_height;

    std::string m_textureID;
};


#endif //LEARN_SDL_LOADERPARAMS_H
