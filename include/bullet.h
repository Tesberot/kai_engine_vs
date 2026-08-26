#pragma once
#include "entity.h"

class Bullet : public Entity {
	
public: 
	float speed = 20.0f;
	Bullet() = default;

	
	void update() override {
		if (!active) return;

		position.y -= speed;

		if (position.y <= 0.0f) {
			active = false;
		}
	}

	void draw() override {
		DrawCircleV(position, 2.0f, WHITE);
	}

};
