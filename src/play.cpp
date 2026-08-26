#include "play.hpp"
#include "raylib.h"
#include <iostream>

namespace kai {
	void Play::init() {
		listen("onclick");
		ship = new Ship();
		ship2 = new Ship();
		bullet = new Bullet();
		ship->setPosition(10, 20);
		ship2->setPosition(20, 40);
		bullet->setPosition(400, 550);

		entityMgr.add(bullet);
		entityMgr.add(ship);
		entityMgr.add(ship2);

		// Code to execute when initializing the play scene

	}

	void Play::exit() {
		stopListening();
		// Code to execute when exiting the pla
	}

	void Play::update() {

		entityMgr.update();

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			EventData data;
			data.type = "onclick";
			EventBus::get().fire("onclick", data);
		}

	}

	void Play::draw() {

		entityMgr.draw();
		// Draw logic for the play scene
		DrawText("Play", 200, 200, 20, WHITE);
	}

	void Play::onEvent(EventData data) {
		std::cout << "Play scene received event: " << data.type << std::endl;

		if (data.type == "onclick") {
			TraceLog(LOG_INFO, "Play scene received onclick event");
		}
	}
}