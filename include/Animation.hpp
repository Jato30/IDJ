#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

#include <string>

class Animation;

#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Collision.hpp"
#include "timer.hpp"

class Animation : public GameObject{
    private:
        Timer endTimer;
        float timeLimit;
        bool oneTimeOnly;
        Sprite sp;

    public:
        Animation(float, float, float, std::string, int, float, bool);
        void Update(float);
        void Render();
        bool IsDead();
        void NotifyCollision(GameObject&);
        bool Is(std::string);
};

#endif // _ANIMATION_HPP_