#pragma once
#include "raylib.h"
#include "circle_collider.h"
#include <string>
namespace kai
{
	class Entity
	{
	public:
		std::string name = "none";
		Vector2 position = {0.0f, 0.0f};
		bool active = true;
		Texture2D texture;
		CircleCollider collider;

		Entity() = default;
		virtual ~Entity() = default;

		virtual void update() {};
		virtual void draw() {};

		void setPosition(float x, float y)
		{
			position.x = x;
			position.y = y;
		}
		void setPosition(Vector2 pos) { position = pos; }
		bool isActive() const { return active; }

		bool collidesWith(const Entity &other)
		{
			return collider.collides(other.collider);
		}
	};
}