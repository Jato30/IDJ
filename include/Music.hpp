#ifndef _MUSIC_HPP_
#define _MUSIC_HPP_

#ifdef _WIN32
    // windows
    #include "SDL.h"
    #include "SDL_image.h"
    #include "SDL_mixer.h"
#elif __APPLE__
    #include "TargetConditionals.h"
    // mac
#elif __linux__
    // linux
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_mixer.h>
#else
    #error "Unknown compiler"
#endif

#include <string>
#include <memory>

class Music{
    private:
        std::shared_ptr<Mix_Music> music;

    public:
        Music();
        Music(std::string);
        void Play(int);
        void Stop();
        void Open(std::string);
        bool IsOpen();
};

#include "Resources.hpp"

#endif // _MUSIC_HPP_