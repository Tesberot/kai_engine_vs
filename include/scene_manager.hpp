#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <string>
#include <unordered_map>
#include "scene.hpp"

namespace kai
{

    class SceneManager
    {
        std::unordered_map<std::string, Scene *> scenes;
        Scene *current = nullptr;
        Scene *next = nullptr;

        SceneManager() = default;
        ~SceneManager()
        {
            if (current)
                current->exit();
            for (auto &[name, scene] : scenes)
                delete scene;
        }

    public:
        static SceneManager &get()
        {
            static SceneManager instance;
            return instance;
        }

        SceneManager(const SceneManager &) = delete;
        void operator=(const SceneManager &) = delete;

        // Registro explícito
        void addScene(const std::string &name, Scene *scene)
        {
            scenes[name] = scene;
        }

        // Transición de estado
        void changeScene(const std::string &name)
        {
            auto it = scenes.find(name);
            if (it == scenes.end())
                return;
            next = it->second;
        }

        // Ciclo de vida del motor
        void update()
        {
            if (current)
            {
                current->update();
            }
            processChange();
        }

        void draw()
        {
            if (current)
                current->draw();
        }

    private:
        void processChange()
        {
            if (!next)
                return;
            if (current)
                current->exit();
            current = next;
            next = nullptr;
            current->init();
        }
    };

}
#endif