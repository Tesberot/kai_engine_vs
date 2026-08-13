#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "raylib.h"

class Circle {
private:
    Vector2 m_position;
    float m_radius;
    Color m_color;

public:
    // Constructors
    Circle() 
        : m_position{ 0.0f, 0.0f }, m_radius{ 10.0f }, m_color{ RED } {}

    Circle(Vector2 position, float radius, Color color = RED)
        : m_position{ position }, m_radius{ radius }, m_color{ color } {}

    // Methods
    void Update(float deltaTime) {
        // Example: Add movement logic or physics updates here
    }

    void Draw(){
        DrawCircleV(m_position, m_radius, m_color);
    }

    // Getters & Setters
    Vector2 GetPosition() { return m_position; }
    void SetPosition(Vector2 pos) { m_position = pos; }

    float GetRadius(){ return m_radius; }
    void SetRadius(float radius) { m_radius = radius; }
};

#endif // CIRCLE_HPP