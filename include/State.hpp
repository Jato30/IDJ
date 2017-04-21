#ifndef _STATE_HPP_
#define _STATE_HPP_

#include <vector>
#include <memory>

class State;

#include "Sprite.hpp"
#include "GameObject.hpp"
#include "TileSet.hpp"
#include "TileMap.hpp"

class State{
    private:
        Sprite bg;
        bool quitRequested;
        std::vector<std::unique_ptr<GameObject>> objectArray;
        TileSet* tileSet;
        TileMap* tileMap;

    public:
        State();
        ~State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float);
        void Render();
        void AddObject(GameObject*);
};

#include <cmath>
#include <string>
#include <cstdlib>
#include "InputManager.hpp"
#include "Camera.hpp"
#include "Alien.hpp"

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

#endif // _STATE_HPP_