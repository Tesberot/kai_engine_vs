#include "play_scene.hpp"

#include "raylib.h"
#include <iostream>

namespace kai {

	void PlayScene::init() {
		listen("onclick");
		ship = new Ship();
		ship->setPosition(10, 20);
		bullets = new Bullet[MAX_BULLETS];
		enemies = new Enemy[MAX_ENEMIES];

		for (int i = 0; i < MAX_BULLETS; i++) {
			entityMgr.add(&bullets[i]);
		}

		for (int i = 0; i < MAX_ENEMIES; i++) {
			//enemies[i].position = { (float)GetRandomValue(0, 800), 5 }; // Random x position at the top of the scree
			//enemies[i].active = true;
			entityMgr.add(&enemies[i]);
		}

		ship->maxBullets = MAX_BULLETS;
		ship->bullets = bullets;
		
		entityMgr.add(ship);
	}

	void PlayScene::exit() {
		stopListening();
		// Code to execute when exiting the pla
	}

	void PlayScene::update() {

		spawnTimer += GetFrameTime();

    if (spawnTimer >= SPAWN_INTERVAL) {
        spawnTimer = 0.0f;

        // Wake an inactive enemy directly
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (!enemies[i].active) {
                enemies[i].position = { (float)GetRandomValue(0, 800), 5 }; // Random x position at the top of the screen
                enemies[i].active = true;
                break;
            }
        }
	}

		entityMgr.update();

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			EventData data;
			data.type = "onclick";
			EventBus::get().fire("onclick", data);
		}

	}

	void PlayScene::draw() {

		entityMgr.draw();
		// Draw logic for the play scene
		DrawText("Play", 200, 200, 20, WHITE);
	}

	void PlayScene::onEvent(EventData data) {
		std::cout << "Play scene received event: " << data.type << std::endl;

		if (data.type == "onclick") {
			TraceLog(LOG_INFO, "Play scene received onclick event");
		}
	}
}