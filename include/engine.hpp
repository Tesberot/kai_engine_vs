#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "raylib.h"
#include "scene_manager.hpp"
#include "assets.hpp"

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
    Assets &assets = Assets::get(); // Asset manager to handle game assets

	int screenWidth = 800;
	int screenHeight = 600;
};

}
#endif // RAY_ENGINE_ENGINE_HPP
