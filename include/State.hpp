#ifndef _STATE_
#define _STATE_

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

        //void Input();
        void AddObject(float, float);

    public:
        State();
        ~State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float);
        void Render();
};

#include <cmath>
#include <string>
#include <cstdlib>
#include "Face.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"

#ifdef _WIN32
    // windows
    #include "SDL.h"
    #include "SDL_image.h"
#elif __APPLE__
   // #include "TargetConditionals.h"
    // mac
#elif __linux__
    // linux
    #include<SDL2/SDL.h>
    #include<SDL2/SDL_image.h>
#else
    #error "Unknown compiler"
#endif

#endif // _STATE_