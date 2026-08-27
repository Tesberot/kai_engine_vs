#pragma once
#include "entity.h"
#include "bullet.h"

#define MAX_AMMO 30

class Ship : public Entity {
public:
	float speed = 20.0f;
	Bullet bullets[MAX_AMMO];

	Ship() {
		name = "Ship";
		active = true;
		position = { 400.0f, 300.0f }; // Starting position (placeholder)
		texture = LoadTexture("ship.png"); // Load ship texture (placeholder)
	}

	~Ship() {
		UnloadTexture(texture); // Unload texture when ship is destroyed
	}

	void update() override {
		// Update ship position based on speed and input (placeholder logic)
		if (IsKeyDown(KEY_RIGHT)) {
			position.x += speed;
		}
		if (IsKeyDown(KEY_LEFT)) {
			position.x -= speed;
		}
		if (IsKeyDown(KEY_UP)) {
			position.y -= speed;
		}
		if (IsKeyDown(KEY_DOWN)) {
			position.y += speed;
		}
		if (IsKeyPressed(KEY_SPACE)){
			fire();
		}

		for(int i = 0; i < MAX_AMMO; i++){
			if(bullets[i].active){
				bullets[i].update();
			}
		}
	}


	void draw() override {
		// Draw the ship (placeholder logic)
		if(isActive() || texture.id != 0) {
			DrawTextureEx(texture, position, 0.0f, 1.0f, WHITE);
		}

		for(int i = 0; i < MAX_AMMO; i++){
			if(bullets[i].active){
				bullets[i].draw();
			}
		}

	}

	void fire(){
		for(int i = 0; i < MAX_AMMO; i++){
			if(!bullets[i].active){
				bullets[i].position.x = position.x +texture.width/2;
				bullets[i].position.y = position.y;
				bullets[i].active = true;
				break;
			}
		}
	}


};