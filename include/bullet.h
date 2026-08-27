#pragma once
#include "entity.h"
#include "raylib.h"

class Bullet : public Entity {
	
public: 
	float speed = 20.0f;
	Bullet(){
		active = false;
	};

	
	void update() override {
		if (!active) return;

		position.y -= speed;

		if (position.y <= 0.0f) {
			active = false;
		}
	}

	void draw() override {
		DrawCircleV(position, 3.0f, WHITE);
	}

};
