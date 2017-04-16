#ifndef _GAMEOBJECT_
#define _GAMEOBJECT_

class GameObject;

#include "Rect.hpp"

class GameObject{
    public:
        Rect box;

        virtual ~GameObject();
        virtual void Update(float) = 0;
        virtual void Render() = 0;
        virtual bool IsDead() = 0;
};

#endif // _GAMEOBJECT_