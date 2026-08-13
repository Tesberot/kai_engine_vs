#include "menu.hpp"
#include "raylib.h"
#include "even_bus.hpp"
#include <iostream>


namespace kai {
    Menu::Menu() {
        listen("start_game");
    }

    Menu::~Menu() {
        // Cleanup code for the menu scene
    }

    void Menu::init(){
        // Code to execute when initializing the menu scene
        menu_gui.show(); // Show the menu GUI when the menu scene is initialized
    }

    void Menu::exit() {
        // Code to execute when exiting the menu scene
    }

    void Menu::update() {
        // Update logic for the menu scene
        if(IsKeyPressed(KEY_M)) {
            menu_gui.toggle(); 
            // Transition to the play scene
        }
    }

    void Menu::draw() {
        		// draw some text using the default font
		DrawText("Menu", 200,200,20,WHITE);
        menu_gui.draw(); // draw the main menu GUI
        DrawFPS(10, 10); // draw the FPS in the top left corner
    }

    void Menu::onEvent(EventData e) {
        if (e.type == "start_game") {
            std::cout << "Start2 Game event received!" << std::endl;
            // Transition to the play scene
        }
    }
}