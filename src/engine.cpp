#include "engine.hpp"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "raylib.h"
#include "assets.hpp"
#include "menu.hpp"
#include "play_scene.hpp"

namespace kai{

void Engine::init()
{
	
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	// Create the window and OpenGL context
	InitWindow(screenWidth, screenHeight, "Hello Raylib");
	TraceLog(LOG_INFO, "Se inicio raylib");
	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");
	assets.init(); // Initialize the asset manager
	sceneMgr.addScene("menu", new Menu()); // Register the menu scene
	sceneMgr.addScene("play", new PlayScene()); // Register the play scene
	sceneMgr.changeScene("menu"); // Set the initial scene to the menu
	
}

void Engine::run()
{
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        update();
        draw();
    }
}

void Engine::update()
{	
	sceneMgr.update(); // Update the current scene
}

void Engine::draw()
{
    // Draw game objects here
    BeginDrawing();
	// Setup the back buffer for drawing (clear color and depth buffers)
	ClearBackground(BLACK);
	sceneMgr.draw(); // Draw the current scene
	EndDrawing();
}

void Engine::shutdown()
{
	sceneMgr.shutdown();
	assets.shutdown(); // Shutdown the asset manager
	//sceneManager.changeScene(nullptr); // Exit the current scene
    // Cleanup and shutdown code here
    CloseWindow();
}

}