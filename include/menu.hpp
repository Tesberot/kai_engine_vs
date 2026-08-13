#ifndef MENU_HPP
#define MENU_HPP
#include "scene.hpp"
#include "kai_gui.hpp"
#include "even_bus.hpp"

namespace kai {
	class Menu : public Scene, public EventListener {
		MenuGUI menu_gui;
		int playEventId;
	public:
		Menu();
		~Menu();
		void init() override;
		void exit() override;
		void update() override;
		void draw() override;
		void onEvent(EventData data) override;
	};
}
#endif // MENU_HPP