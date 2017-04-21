#include "Sprite.hpp"

Sprite::Sprite(){
    texture = nullptr;
    scaleX = 1;
    scaleY = 1;
}

Sprite::Sprite(std::string file){
    texture = nullptr;
    scaleX = 1;
    scaleY = 1;
    Open(file);
}

Sprite::~Sprite(){

}

void Sprite::Open(std::string file){
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

void Sprite::Render(int x, int y, float angle){
    SDL_Rect* dstrect = new SDL_Rect();

    angle *= 180 / M_PI;
    dstrect->x = x;
    dstrect->y = y;
    dstrect->w = clipRect.w * scaleX;
    dstrect->h = clipRect.h * scaleY;
    SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, dstrect, (double) angle, nullptr, SDL_FLIP_NONE);
}

int Sprite::GetWidth(){
    return width * scaleX;
}

int Sprite::GetHeight(){
    return height * scaleY;
}

bool Sprite::IsOpen(){
    return texture != nullptr;
}

void Sprite::SetScaleX(float scale){
    scaleX = scale;
}

void Sprite::SetScaleY(float scale){
    scaleY = scale;
}