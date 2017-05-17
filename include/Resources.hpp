#ifndef _RESOURCES_HPP_
#define _RESOURCES_HPP_

#ifdef _WIN32
    // windows
    #include "SDL.h"
    #include "SDL_image.h"
    #include "SDL_mixer.h"
    #include "SDL_ttf.h"
#elif __APPLE__
    #include "TargetConditionals.h"
    // mac
#elif __linux__
    // linux
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_mixer.h>
    #include <SDL2/SDL_ttf.h>
#else
    #error "Unknown compiler"
#endif

#include <unordered_map>
#include <string>
#include <memory>

class Resources{
    private:
        static std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> imageTable;
        static std::unordered_map<std::string, std::shared_ptr<Mix_Music>> musicTable;
        static std::unordered_map<std::string, std::shared_ptr<Mix_Chunk>> soundTable;
        static std::unordered_map<std::string, std::shared_ptr<TTF_Font>> fontTable;

    public:
        static std::shared_ptr<SDL_Texture> GetImage(std::string);
        static void ClearImages();
        static std::shared_ptr<Mix_Music> GetMusic(std::string);
        static void ClearMusics();
        static std::shared_ptr<Mix_Chunk> GetSound(std::string);
        static void ClearSounds();
        static std::shared_ptr<TTF_Font> GetFont(std::string, int);
        static void ClearFonts();
};

#include "Game.hpp"

#endif // _RESOURCES_HPP_