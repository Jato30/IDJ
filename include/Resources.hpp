#ifndef _RESOURCES_
#define _RESOURCES_

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

#include <unordered_map>
#include <string>

class Resources{
    private:
        static std::unordered_map<std::string, SDL_Texture*> imageTable;

    public:
        static SDL_Texture* GetImage(std::string);
        static void ClearImages();
};

#include "Game.hpp"

#endif // _RESOURCES_