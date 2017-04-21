#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

class Camera;

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

#define CAMERA_SPEED 250 // Velocidade base

#endif // _CAMERA_