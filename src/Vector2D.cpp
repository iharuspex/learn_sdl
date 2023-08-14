#include "Vector2D.h"

Vector2D::Vector2D(float x, float y) : m_x(x), m_y(y) {

}

float Vector2D::getX() {
    return m_x;
}

float Vector2D::getY() {
    return m_y;
}

void Vector2D::setX(float x) {
    m_x = x;
}

void Vector2D::setY(float y) {
    m_y = y;
}

float Vector2D::length() const {
    return sqrt(m_x * m_x + m_y * m_y);
}

void Vector2D::normalize() {
    float len = length();

    if ( len > 0) {
        (*this) *= 1 / len;
    }
}

Vector2D Vector2D::operator + (const Vector2D &v2) const {
    return { m_x + v2.m_x, m_y + v2.m_y };
}

Vector2D &operator += (Vector2D &v1, const Vector2D &v2) {
    v1.m_x += v2.m_x;
    v1.m_y += v2.m_y;

    return v1;
}

Vector2D Vector2D::operator - (const Vector2D &v2) const {
    return { m_x - v2.m_x, m_y - v2.m_y };
}

Vector2D &operator -= (Vector2D &v1, const Vector2D &v2) {
    v1.m_x - v2.m_x;
    v1.m_y - v2.m_y;

    return v1;
}

Vector2D Vector2D::operator * (float scalar) const {
    return { m_x * scalar, m_y * scalar };
}

Vector2D &Vector2D::operator *= (float scalar) {
    m_x *= scalar;
    m_y *= scalar;

    return *this;
}

Vector2D Vector2D::operator / (float scalar) const {
    return { m_x / scalar, m_y / scalar };
}

Vector2D &Vector2D::operator /= (float scalar) {
    m_x /= scalar;
    m_y /= scalar;

    return *this;
}
