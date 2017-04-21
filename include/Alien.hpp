#ifndef _ALIEN_HPP_
#define _ALIEN_HPP_

#include <queue>
#include <vector>

class Alien;

#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Vec2.hpp"
#include "Minion.hpp"

class Alien : public GameObject{
    private:
        class Action{
            public:
                typedef enum ActionType{
                    SHOOT,
                    MOVE
                } ActionType;
                
                ActionType type;
                Vec2 pos;

                Action(ActionType, float, float);
        };

        Sprite sp;
        Vec2 speed;
        int hp;
        std::queue<Action> taskQueue;
        std::vector<Minion> minionArray;

    public:
        Alien(float, float, int);
        ~Alien();
        void Update(float);
        void Render();
        bool IsDead();
};

#include "Rect.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"

#endif // _ALIEN_HPP_