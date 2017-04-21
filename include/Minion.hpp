#ifndef _MINION_HPP_
#define _MINION_HPP_

#define RAIO 100

class Minion;

#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Vec2.hpp"

class Minion : public GameObject{
    private:
        GameObject* center;
        Sprite sp;
        float arc;

    public:
        Minion(GameObject*, float);
        ~Minion();
        void Update(float);
        void Render();
        bool IsDead();
        void Shoot(Vec2);
};

#include <cstdlib>

#include "Rect.hpp"
#include "Camera.hpp"
#include "Bullet.hpp"
#include "State.hpp"

#endif // _MINION_HPP_