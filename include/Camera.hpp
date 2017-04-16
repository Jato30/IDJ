#ifndef _CAMERA_
#define _CAMERA_

#include "GameObject.hpp"
#include "Vec2.hpp"

class Camera{
    private:
        static GameObject* focus;

    public:
        static Vec2 pos;
        static Vec2 speed;
        
        static void Follow(GameObject*);
        static void UnFollow();
        static void Update(float);
};

#include "InputManager.hpp"

#define CAMERA_SPEED 250

#endif // _CAMERA_