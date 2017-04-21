#include "Bullet.hpp"

Bullet::Bullet(float x, float y, float angle, float speed, float maxDistance, std::string sprite) : GameObject(){
    sp = Sprite(sprite);
    box = Rect(x, y, sp.GetWidth(), sp.GetHeight());
    Bullet::speed.x = speed * std::cos(angle);
    Bullet::speed.y = speed * std::sin(angle);
    distanceLeft = maxDistance;
    rotation = angle;
}

void Bullet::Update(float dt){
    Vec2 bulletHead(box.x + (box.w / 2), box.y + (box.h / 2));

    box.x += speed.x * dt;
    box.y += speed.y * dt;
    distanceLeft -= std::sqrt(std::pow((box.x + (box.w / 2)) - bulletHead.x, 2) + std::pow((box.y + (box.h / 2)) - bulletHead.y, 2));
}

void Bullet::Render(){
    sp.Render((int) (box.x - (box.w / 2)) + Camera::pos.x, (int) (box.y - (box.h / 2)) + Camera::pos.y, rotation);
}

bool Bullet::IsDead(){
    return distanceLeft < 0;
}