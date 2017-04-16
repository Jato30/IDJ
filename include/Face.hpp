#ifndef _FACE_
#define _FACE_

class Face;

#include "GameObject.hpp"
#include "Sprite.hpp"

class Face : public GameObject{
    private:
        int hitpoints;
        Sprite sp;

    public:
        Face(float, float);
        void Damage(int);
        void Update(float);
        void Render();
        bool IsDead();
};

#include <cstdlib>
#include "State.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"

#endif // _FACE_