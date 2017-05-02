#include "Sprite.hpp"

Sprite::Sprite(){
    texture = nullptr;
    scaleX = 1.0;
    scaleY = 1.0;
    frameTime = 1.0;
    frameCount = 1;
    timeElapsed = 0.0;
    currentFrame = 0;
}

Sprite::Sprite(std::string file, int frameCount, float frameTime){
    texture = nullptr;
    scaleX = 1.0;
    scaleY = 1.0;
    timeElapsed = 0.0;
    currentFrame = 0;
    this->frameCount = frameCount;
    this->frameTime = frameTime;
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
    SetClip(currentFrame, 0, (width / frameCount), height);
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
    return (width / frameCount) * scaleX;
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

void Sprite::SetScale(float scale){
    scaleX = scale;
    scaleY = scale;
}

void Sprite::Update(float dt){
    timeElapsed += dt;
    if(timeElapsed > frameTime){
        timeElapsed -= frameTime;
        currentFrame = (currentFrame + 1) % frameCount;
        clipRect.x = currentFrame * (width / frameCount);
    }
    if(currentFrame > width){
        currentFrame = 0;
    }
}

void Sprite::SetFrame(int frame){
    currentFrame = frame % frameCount;
    clipRect.x = currentFrame * (width / frameCount);
}

void Sprite::SetFrameCount(int frameCount){
    this->frameCount = frameCount;
    clipRect.w = width / frameCount;
}

void Sprite::SetFrameTime(float frameTime){
    this->frameTime = frameTime;
}