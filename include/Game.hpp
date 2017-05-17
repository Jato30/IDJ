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
#include <stack>
#include <memory>

class Game;

#include "State.hpp"

class Game{
    private:
        int frameStart;
        float dt;
        static Game* instance;
        State* storedState;
        SDL_Window* window;
        SDL_Renderer* renderer;
        std::stack<std::unique_ptr<State>> stateStack;

        void CalculateDeltaTime();

    public:
        Game(std::string, int, int);
        ~Game();
        static Game& GetInstance();
        SDL_Renderer* GetRenderer();
        State& GetCurrentState();
        void Push(State*);
        void Run();
        float GetDeltaTime();
};

#include "Resources.hpp"
#include "InputManager.hpp"

#endif // _GAME_HPP_