#pragma once

#include "raylib.h"
#include "raymath.h"

namespace kai
{

    class CircleCollider
    {
    public:
        Vector2 center = {0.0f, 0.0f};
        float radius = 10.0f;

        CircleCollider(float r = 10.0f) : radius(r) {}

        void update(Vector2 pos)
        {
            center = pos;
        }

        bool collides(const CircleCollider &other)
        {
            return Vector2Distance(center, other.center) <= (radius + other.radius);
        }

        void debugDraw(Color color = GREEN) const
        {
            DrawCircleLines((int)center.x, (int)center.y, radius, color);
            DrawCircleV(center, 3.0f, color);
        }
    };

}