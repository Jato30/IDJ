#include "Bullet.hpp"

Bullet::Bullet(float x, float y, float angle, float speed, float maxDistance, std::string sprite, float frameTime, int frameCount, bool target) : GameObject(){
    sp = Sprite(sprite);
    sp.SetFrameTime(frameTime);
    sp.SetFrameCount(frameCount);
    box = Rect(x, y, sp.GetWidth(), sp.GetHeight());
    Bullet::speed.x = speed * std::cos(angle);
    Bullet::speed.y = speed * std::sin(angle);
    distanceLeft = maxDistance;
    rotation = angle;
    targetsPlayer = target;
}

void Bullet::Update(float dt){
    sp.Update(dt);
    Vec2 bulletHead(box.GetCenter().x, box.GetCenter().y);

    box.x += speed.x * dt;
    box.y += speed.y * dt;
    distanceLeft -= std::sqrt(std::pow((box.GetCenter().x) - bulletHead.x, 2) + std::pow((box.GetCenter().y) - bulletHead.y, 2));
}

void Bullet::Render(){
    sp.Render((int) (box.x - (box.w / 2)) + Camera::pos.x, (int) (box.y - (box.h / 2)) + Camera::pos.y, rotation);
}

bool Bullet::IsDead(){
    return distanceLeft < 0;
}

void Bullet::NotifyCollision(GameObject& other){
    if(!other.Is("Bullet")){
        if(!targetsPlayer && other.Is("Alien")){
            distanceLeft = -1;
        }
        if(targetsPlayer && !other.Is("Alien")){
            distanceLeft = -1;
        }
    }
}

bool Bullet::Is(std::string type){
    return (type == "Bullet");
}