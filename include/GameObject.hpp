#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

// Velocidades base
#define OBJECT_LINEAR_SPEED 70
#define OBJECT_LINEAR_MAX_SPEED 350
#define OBJECT_ANGULAR_SPEED M_PI / 6

#include <string>

class GameObject;

#include "Rect.hpp"

class GameObject{
    public:
        Rect box;
        float rotation;

        GameObject();
        virtual ~GameObject();
        virtual void Update(float) = 0;
        virtual void Render() = 0;
        virtual bool IsDead() = 0;
        virtual void NotifyCollision(GameObject&) = 0;
        virtual bool Is(std::string) = 0;
};

#endif // _GAMEOBJECT_HPP_