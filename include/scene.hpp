#ifndef SCENE_HPP
#define SCENE_HPP

namespace kai {
    class Scene {
    public:
        virtual ~Scene() = default;
        virtual void init() = 0;
        virtual void exit() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
    };
}

#endif // SCENE_HPP