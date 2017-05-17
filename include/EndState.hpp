#ifndef _ENDSTATE_HPP_
#define _ENDSTATE_HPP_

class EndState;

#include "Sprite.hpp"
#include "Music.hpp"
#include "Text.hpp"
#include "StateData.hpp"
#include "State.hpp"

class EndState : public State{
    private:
        Sprite bg;
        Music music;
        Text instruction;
    
    public:
        EndState(StateData);
        void Update(float);
        void Render();
        void Pause();
        void Resume();
        void LoadAssets();
};

#include "InputManager.hpp"
#include "Resources.hpp"
#include "Game.hpp"
#include "StageState.hpp"
#include "Timer.hpp"

#endif // _ENDSTATE_HPP_