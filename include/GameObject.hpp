#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

// Velocidades base
#define OBJECT_SPEED 75
#define MINION_SPEED M_PI / 6

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
};

#endif // _GAMEOBJECT_HPP_