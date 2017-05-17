#ifndef _TEXT_HPP_
#define _TEXT_HPP_

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

#include <string>
#include <memory>

class Text;

#include "Rect.hpp"
#include "Timer.hpp"

class Text{
    public:
        typedef enum{
            SOLID,
            SHADED,
            BLENDED
        } TextStyle;
        
    private:
        Rect box;
        SDL_Color color;
        int fontSize;
        TextStyle style;
        std::string text;
        SDL_Texture* texture;
        std::shared_ptr<TTF_Font> font;
        Timer* delay;

        void RemakeTexture();

    public:
        typedef enum{
            BLACK,
            WHITE,
            GRAY,
            RED,
            YELLOW,
            BLUE,
            GREEN,
            CYAN
        } Colors;

        Text(std::string, int, TextStyle, std::string, SDL_Color, Timer* = nullptr, int = 0, int = 0);
        ~Text();
        void Render(int = 0, int = 0);
        void SetPos(int, int, bool = false, bool = false);
        void SetText(std::string);
        void SetColor(SDL_Color);
        void SetStyle(TextStyle);
        void SetFontSize(int);
        // Canal alpha vai de -255 até 255 e determina o brilho
        static SDL_Color GetColor(Colors);
};

#include "Game.hpp"

#endif // _TEXT_HPP_