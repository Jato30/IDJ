#include "Sprite.hpp"

Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(std::string file){
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    /*if(texture != nullptr){
        SDL_DestroyTexture(texture);
    }*/
}

void Sprite::Open(std::string file){
    /*if(texture != nullptr){
        SDL_DestroyTexture(texture);
    }
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());*/
    texture = Resources::GetImage(file);
    if(texture == nullptr){
        printf("Impossível carregar imagem: %s", SDL_GetError());
        exit(0);
    }
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y){
    SDL_Rect* dstrect = new SDL_Rect();
    dstrect->x = x;
    dstrect->y = y;
    dstrect->w = clipRect.w;
    dstrect->h = clipRect.h;
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, dstrect);
}

int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

bool Sprite::IsOpen(){
    return texture != nullptr;
}