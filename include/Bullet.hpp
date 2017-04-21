#ifndef _BULLET_HPP_
#define _BULLET_HPP_

#include <string>

class Bullet;

#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Vec2.hpp"

class Bullet : public GameObject{
    private:
        Sprite sp;
        Vec2 speed;
        float distanceLeft;

    public:
        Bullet(float, float, float, float, float, std::string);
        void Update(float);
        void Render();
        bool IsDead();
};

#include "Camera.hpp"
#include "Game.hpp"

#endif // _BULLET_HPP_