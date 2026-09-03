#pragma once
#include "entity.h"
#include "raylib.h"

using namespace kai;

class Bullet : public Entity {
	
public: 
	float speed = 10.0f;
	int radius = 3;
	Bullet(){
		active = false;
		collider.radius = 3;
	};

	
	void update() override {
		if (!active) return;

		position.y -= speed;

		if (position.y <= 0.0f) {
			active = false;
		}
	}

	void draw() override {
		DrawCircleV(position, radius, WHITE);
	}

};
