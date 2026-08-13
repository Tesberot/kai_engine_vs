#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "raylib.h"
#include "scene_manager.hpp"	// utility header for SceneManager class

namespace kai{

//Make a change
class Engine {
public:
    Engine() = default;
    ~Engine() = default;

    void init();
    void run();
    void update();
    void draw();
    void shutdown();

	SceneManager &sceneMgr = SceneManager::get(); // Scene manager to handle different scenes

	int screenWidth = 800;
	int screenHeight = 600;
};

}
#endif // RAY_ENGINE_ENGINE_HPP
