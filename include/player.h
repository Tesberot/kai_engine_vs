#pragma once
#include <raylib.h>
#include "even_bus.hpp"

class Player {
public:

	void grabCoin() {
		EventData data;
		data.type = "grab_coin";
		EventBus::get().fire("grab_coin", data);
	}

	void enemyHit() {
		EventData data;
		data.type = "enemy_hit";
		EventBus::get().fire("enemy_hit", data);
	}

	void playerHit() {
		EventData data;
		data.type = "player_hit";
		data.intVal = 20;
		EventBus::get().fire("player_hit", data);
	}
};
