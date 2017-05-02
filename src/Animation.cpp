#include "Animation.hpp"

Animation::Animation(float x, float y, float rotation, std::string sprite, int frameCount, float frameTime, bool ends) : GameObject(){
    this->rotation = rotation;
    sp = Sprite(sprite, frameCount, frameTime);
    box = Rect(x, y, sp.GetWidth(), sp.GetHeight());

    sp.SetFrameTime(frameTime);
    sp.SetFrameCount(frameCount);
    timeLimit = frameCount * frameTime;
    endTimer = Timer();
    oneTimeOnly = ends;
}

void Animation::Update(float dt){
    endTimer.Update(dt);
    sp.Update(dt);
}

void Animation::Render(){
    sp.Render((int) box.x + Camera::pos.x, (int) box.y+ Camera::pos.y, rotation);
}

bool Animation::IsDead(){
    return (endTimer.Get() >= timeLimit) && oneTimeOnly;
}

void Animation::NotifyCollision(GameObject& other){
    if(!other.Is("")){

    }
}

bool Animation::Is(std::string type){
    return (type == "Animation");
}