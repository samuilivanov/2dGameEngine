#include "vector2d.h"

namespace SFGE {

    Vector2D::Vector2D() : x(0.0f), y(0.0f) {}
    Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

    Vector2D& Vector2D::add(const Vector2D& vec)
    {
        this->x += vec.x;
        this->y += vec.y;
        return *this;
    }

    Vector2D& Vector2D::substract(const Vector2D& vec)
    {
        this->x -= vec.x;
        this->y -= vec.y;
        return *this;
    }

    Vector2D& Vector2D::multiply(const Vector2D& vec)
    {
        this->x *= vec.x;
        this->y *= vec.y;
        return *this;
    }

    Vector2D& Vector2D::divide(const Vector2D& vec)
    {
        this->x /= vec.x;
        this->y /= vec.y;
        return *this;
    }

    Vector2D operator + (Vector2D& v1, const Vector2D& v2)
    {
        return v1.add(v2);
    }

    Vector2D operator - (Vector2D& v1, const Vector2D& v2)
    {
        return v1.substract(v2);
    }

    Vector2D operator * (Vector2D& v1, const Vector2D& v2)
    {
        return v1.multiply(v2);
    }

    Vector2D operator / (Vector2D& v1, const Vector2D& v2)
    {
        return v1.divide(v2);
    }

    Vector2D Vector2D::operator += (const Vector2D& vec)
    {
        return this->add(vec);
    }

    Vector2D Vector2D::operator -= (const Vector2D& vec)
    {
        return this->substract(vec);
    }

    Vector2D Vector2D::operator *= (const Vector2D& vec)
    {
        return this->multiply(vec);
    }

    Vector2D Vector2D::operator /= (const Vector2D& vec)
    {
        return this->divide(vec);
    }

    std::ostream &operator << (std::ostream &os, const Vector2D &vec)
    {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }

}
