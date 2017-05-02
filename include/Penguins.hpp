#ifndef _PENGUINS_HPP_
#define _PENGUINS_HPP_

class Penguins;

#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Vec2.hpp"
#include "Timer.hpp"

class Penguins : public GameObject{
    private:
        Sprite bodySp;
        Sprite cannonSp;
        Vec2 speed;
        float linearSpeed;
        float cannonAngle;
        int hp;
        Timer cooldown;

    public:
        static Penguins* player;

        Penguins(float, float);
        ~Penguins();
        void Update(float);
        void Render();
        bool IsDead();
        void Shoot();
        void NotifyCollision(GameObject&);
        bool Is(std::string);
};

#include "InputManager.hpp"
#include "Camera.hpp"
#include "Animation.hpp"
#include "Game.hpp"

#endif // _PENGUINS_HPP_