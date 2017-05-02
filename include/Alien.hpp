#ifndef _ALIEN_HPP_
#define _ALIEN_HPP_

#include <queue>
#include <vector>
#include <string>

class Alien;

#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Vec2.hpp"
#include "Minion.hpp"
#include "Timer.hpp"

class Alien : public GameObject{
    private:
        typedef enum{
            MOVING,
            RESTING
        } AlienState;

        Sprite sp;
        Vec2 speed;
        int hp;
        std::vector<Minion> minionArray;
        AlienState state;
        Timer restTimer;
        Vec2 destination;
        Timer shootCooldown;

    public:
        static int alienCount;

        Alien(float, float, int);
        ~Alien();
        void Update(float);
        void Render();
        bool IsDead();
        void NotifyCollision(GameObject&);
        bool Is(std::string);
};

#include "Rect.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"

#endif // _ALIEN_HPP_