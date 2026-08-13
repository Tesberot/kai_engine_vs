#include "play.hpp"
#include "raylib.h"

namespace kai {
	void Play::init() {
		// Code to execute when initializing the play scene
		listen("grab_coin");
		listen("enemy_hit");
		listen("player_hit");
	}

	void Play::exit() {
		// Code to execute when exiting the play scene
	}

	void Play::update() {
		if (IsKeyPressed(KEY_C)) {
			player.grabCoin();
		}
		if (IsKeyPressed(KEY_E)) {
			player.enemyHit();
		}
		if (IsKeyPressed(KEY_P)) {
			player.playerHit();
		}
		// Update logic for the play scene
	}

	void Play::draw() {
		// Draw logic for the play scene
		DrawText("Play", 200, 200, 20, WHITE);
	}

	void Play::onEvent(EventData data) {
		if (data.type == "grab_coin") {
			TraceLog(LOG_INFO, "Se agarro una moneda");
		}
		else if (data.type == "enemy_hit") {
			TraceLog(LOG_INFO, "Enemigo golpeado");
		}
		else if (data.type == "player_hit") {
			TraceLog(LOG_INFO, "El jugador fue golpeado");
		}
	}
}