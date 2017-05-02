#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

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

class Sprite{
    private:
        SDL_Texture* texture;
        int width;
        int height;
        SDL_Rect clipRect;
        float scaleX;
        float scaleY;
        int frameCount;
        int currentFrame;
        float timeElapsed;
        float frameTime;

    public:
        Sprite();
        Sprite(std::string, int = 1, float = 1);
        ~Sprite();
        void Open(std::string);
        void SetClip(int, int, int, int);
        void Render(int, int, float = 0);
        int GetWidth();
        int GetHeight();
        bool IsOpen();
        void SetScaleX(float);
        void SetScaleY(float);
        void SetScale(float);
        void Update(float);
        void SetFrame(int);
        void SetFrameCount(int);
        void SetFrameTime(float);
};

#include "Game.hpp"
#include "Resources.hpp"

#endif // _SPRITE_HPP_