#ifndef PLAY_HPP
#define PLAY_HPP
#include "scene.hpp"
#include "even_bus.hpp"
#include "player.h"



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

		Player player;
		int eventId_01;
		int eventId_02;
		int playerScore;
		int grabCoinEvId;
	};
} // namespace kai
#endif // PLAY_HPP