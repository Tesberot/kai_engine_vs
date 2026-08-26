#ifndef PLAY_HPP
#define PLAY_HPP
#include "scene.hpp"
#include "even_bus.hpp"
#include "ship.h"
#include "bullet.h"
#include "entity_manager.h"



namespace kai {
	class Play : public Scene, EventListener {
	public:
		Play() = default;
		~Play() = default;

		void init() override;
		void exit() override;
		void update() override;
		void draw() override;
		void onEvent(EventData data) override;

		EntityManager entityMgr;
		Ship* ship;
		Ship* ship2;
		Bullet* bullet;
		int eventId_01;
		int eventId_02;
		int playerScore;
		int grabCoinEvId;
	};
} // namespace kai
#endif // PLAY_HPP