#ifndef _GAME_HPP_
#define _GAME_HPP_

#define M_PI 3.14159265358979323846264338327950288

#ifdef _WIN32
    // windows
    #include "SDL.h"
    #include "SDL_image.h"
#elif __APPLE__
    #include "TargetConditionals.h"
    // mac
#elif __linux__
    // linux
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
#else
    #error "Unknown compiler"
#endif

#include <string>

class Game;

#include "State.hpp"

class Game{
    private:
        static Game* instance;
        SDL_Window* window;
        SDL_Renderer* renderer;
        State* state;
        int frameStart;
        float dt;

        void CalculateDeltaTime();

    public:
        Game(std::string, int, int);
        ~Game();
        void Run();
        SDL_Renderer* GetRenderer();
        State& GetState();
        static Game& GetInstance();
        float GetDeltaTime();
};

#include "Sprite.hpp"
#include "Resources.hpp"
#include "InputManager.hpp"

#endif // _GAME_HPP_