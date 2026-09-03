#ifndef PLAY_HPP
#define PLAY_HPP
#include "scene.hpp"
#include "even_bus.hpp"
#include "ship.h"
#include "bullet.h"
#include "entity_manager.h"
#include "enemy.h"

#define MAX_BULLETS 30
#define MAX_ENEMIES 10

namespace kai {

	class PlayScene : public Scene, EventListener {
	public:
		PlayScene() = default;
		~PlayScene() = default;

		void init() override;
		void exit() override;
		void update() override;
		void draw() override;
		void onEvent(EventData data) override;

		EntityManager entityMgr;
		Ship* ship;
		Bullet* bullets;
		Enemy* enemies;
		float spawnTimer = 0.0f;
		float SPAWN_INTERVAL = 2.0f;

		int eventId_01;
		int eventId_02;
		int playerScore;
		int grabCoinEvId;
	};
} // namespace kai
#endif // PLAY_HPP