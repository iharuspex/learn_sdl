#ifndef LEARN_SDL_VECTOR2D_H
#define LEARN_SDL_VECTOR2D_H

#include <cmath>

class Vector2D {
public:
    Vector2D(float x, float y);

    float getX();
    float getY();

    void setX(float x);
    void setY(float y);

    [[nodiscard]] float length() const;

    void normalize();

    Vector2D operator + (const Vector2D& v2) const;
    friend Vector2D& operator += (Vector2D& v1, const Vector2D& v2);

    Vector2D operator - (const Vector2D& v2) const;
    friend Vector2D& operator -= (Vector2D& v1, const Vector2D& v2);

    Vector2D operator * (float scalar) const;
    Vector2D& operator *= (float scalar);

    Vector2D operator / (float scalar) const;
    Vector2D& operator /= (float scalar);

private:
    float m_x;
    float m_y;
};


#endif //LEARN_SDL_VECTOR2D_H
