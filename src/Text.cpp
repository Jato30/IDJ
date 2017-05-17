#include "Text.hpp"

Text::Text(std::string fontFile, int fontSize, TextStyle style, std::string text, SDL_Color color, Timer* textTime, int x, int y){
    texture = nullptr;
    delay = textTime;
    this->fontSize = fontSize;
    this->style = style;
    this->text = text;
    this->color = color;
    font = Resources::GetFont(fontFile, fontSize);
    box.x = x;
    box.y = y;
    RemakeTexture();
}

Text::~Text(){
    if(texture != nullptr){
        SDL_DestroyTexture(texture);
    }
}

void Text::Render(int cameraX, int cameraY){
    delay->Update(Game::GetInstance().GetDeltaTime());
    if(delay != nullptr ? delay->Get() < 0.6 : true){
        if(texture != nullptr){
            SDL_Rect srcRect = SDL_Rect();
            SDL_Rect dstRect = SDL_Rect();

            srcRect.x = 0;
            srcRect.y = 0;
            srcRect.w = box.w;
            srcRect.h = box.h;

            dstRect.x = box.x + cameraX;
            dstRect.y = box.y + cameraY;
            dstRect.w = box.w;
            dstRect.h = box.h;
            SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &srcRect, &dstRect);
        }
    }
    else if(delay != nullptr ? delay->Get() >= 1 : false){
        delay->Restart();
    }
}

void Text::SetPos(int x, int y, bool centerX, bool centerY){
    if(centerX){
        box.x = x - (box.w / 2);
    }
    else{
        box.x = x;
    }
    if(centerY){
        box.y = y - (box.h / 2);
    }
    else{
        box.y = y;
    }
}

void Text::SetText(std::string text){
    this->text = text;
    RemakeTexture();
}

void Text::SetColor(SDL_Color color){
    this->color = color;
    RemakeTexture();
}

void Text::SetStyle(TextStyle style){
    this->style = style;
    RemakeTexture();
}

void Text::SetFontSize(int size){
    fontSize = size;
    RemakeTexture();
}

void Text::RemakeTexture(){
    if(texture != nullptr){
        SDL_DestroyTexture(texture);
    }
    
    switch(style){
        case Text::TextStyle::SOLID:
            texture = SDL_CreateTextureFromSurface(Game::GetInstance().GetRenderer(), TTF_RenderText_Solid(font.get(), text.c_str(), color));
            break;
        
        case Text::TextStyle::SHADED:
            texture = SDL_CreateTextureFromSurface(Game::GetInstance().GetRenderer(), TTF_RenderText_Shaded(font.get(), text.c_str(), color, GetColor(Colors::BLACK)));
            break;

        case Text::TextStyle::BLENDED:
            texture = SDL_CreateTextureFromSurface(Game::GetInstance().GetRenderer(), TTF_RenderText_Blended(font.get(), text.c_str(), color));
            break;
    }
    int w, h;
    if(SDL_QueryTexture(texture, nullptr, nullptr, &w, &h) != 0){
        printf("Impossível obter dimensões do texto: %s", SDL_GetError());
    }
    box.w = w;
	box.h = h;
}

SDL_Color Text::GetColor(Text::Colors name){
    SDL_Color codColor;

    switch(name){
        case Text::Colors::BLACK:
            codColor.r = 0;
            codColor.g = 0;
            codColor.b = 0;
            codColor.a = 0;
            break;

        case Text::Colors::WHITE:
            codColor.r = 255;
            codColor.g = 255;
            codColor.b = 255;
            codColor.a = 255;
            break;
        
        case Text::Colors::GRAY:
            codColor.r = 127;
            codColor.g = 127;
            codColor.b = 127;
            codColor.a = 191;
            break;
        
        case Text::Colors::RED:
            codColor.r = 255;
            codColor.g = 0;
            codColor.b = 0;
            codColor.a = 191;
            break;

        case Text::Colors::YELLOW:
            codColor.r = 255;
            codColor.g = 255;
            codColor.b = 0;
            codColor.a = 127;
            break;
        
        case Text::Colors::BLUE:
            codColor.r = 0;
            codColor.g = 0;
            codColor.b = 255;
            codColor.a = 191;
            break;

        case Text::Colors::GREEN:
            codColor.r = 0;
            codColor.g = 255;
            codColor.b = 0;
            codColor.a = 191;
            break;
        
        case Text::Colors::CYAN:
            codColor.r = 0;
            codColor.g = 191;
            codColor.b = 255;
            codColor.a = 255;
            break;
    }
    
    return codColor;
}