#ifndef _SPRITE_
#define _SPRITE_

#ifdef _WIN32
    // windows
    #include "SDL.h"
    #include "SDL_image.h"
#elif __APPLE__
  //  #include "TargetConditionals.h"
    // mac
#elif __linux__
    // linux
    #include<SDL2/SDL.h>
    #include<SDL2/SDL_image.h>
#else
    #error "Unknown compiler"
#endif

#include <string>

class Sprite{
    private:
        SDL_Texture* texture;
        int width;
        int height;
        SDL_Rect clipRect;

    public:
        Sprite();
        Sprite(std::string);
        ~Sprite();
        void Open(std::string);
        void SetClip(int, int, int, int);
        void Render(int, int);
        int GetWidth();
        int GetHeight();
        bool IsOpen();
};

#include "Game.hpp"
#include "Resources.hpp"

#endif // _SPRITE_