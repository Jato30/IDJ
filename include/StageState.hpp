#ifndef _STAGESTATE_HPP_
#define _STAGESTATE_HPP_

#include <vector>
#include <memory>

class StageState;

#include "Sprite.hpp"
#include "TileSet.hpp"
#include "TileMap.hpp"
#include "State.hpp"
#include "Music.hpp"

class StageState : public State{
    private:
        Sprite bg;
        TileSet* tileSet;
        TileMap* tileMap;
        Music bgSong;
        Timer toEnd;
        Timer alienRespawn;

    public:
        StageState();
        ~StageState();
        void Update(float);
        void Render();
        void LoadAssets();
        void Pause();
        void Resume();
};

#include <string>
#include "InputManager.hpp"
#include "Camera.hpp"
#include "Alien.hpp"
#include "Penguins.hpp"
#include "TitleState.hpp"
#include "Game.hpp"
#include "EndState.hpp"
#include "StateData.hpp"

#ifdef _WIN32
    // windows
    #include "SDL.h"
    #include "SDL_image.h"
#elif __APPLE__
    #include "TargetConditionals.h"
    // mac
#elif __linux__
    // linux
    #include<SDL2/SDL.h>
    #include<SDL2/SDL_image.h>
#else
    #error "Unknown compiler"
#endif

#endif // _STAGESTATE_HPP_