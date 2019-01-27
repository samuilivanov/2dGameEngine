#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "components.h"
// Make sure this include properly
#include "../vector2d.h"

namespace SFGE {

    class TransformComponent : public Component
    {
    public:
        Vector2D position;
        Vector2D velocity;
        int speed = 3;
        TransformComponent()
        {
            position.x = 0.0f;
            position.y = 0.0f;
        }
        TransformComponent(int x, int y)
        {
            position.x = x;
            position.x = y;
        }

        void init() override
        {
            velocity.x = 0;
            velocity.y = 0;
        }
        void update() override
        {
            position.x += velocity.x * speed;
            position.y += velocity.y * speed;
        }
    };
}

#endif // TRANSFORMCOMPONENT_H
