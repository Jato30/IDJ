#include "Minion.hpp"

Minion::Minion(GameObject* minionCenter, float arcOffSet) : GameObject(), sp("./resources/img/minion.png"){
    center = minionCenter;
    arc = arcOffSet;

    float scale = (float) ((rand() % 50) + 100) / 100;
    sp.SetScaleX(scale);
    sp.SetScaleY(scale);
    box = Rect(center->box.x + center->box.w + (RAIO * std::cos(arc)), center->box.y + center->box.h + (RAIO * std::sin(arc)), sp.GetWidth(), sp.GetHeight());
}

Minion::~Minion(){

}

void Minion::Update(float dt){
    box.x = center->box.x + (RAIO * std::cos(arc));
    box.y = center->box.y + (RAIO * std::sin(arc));
    arc += OBJECT_ANGULAR_SPEED * dt;

    if(arc > 2 * M_PI){
        arc -= (2 * M_PI);
    }
    rotation = arc;
}

void Minion::Render(){
    sp.Render((int) (box.x + box.w/2) + Camera::pos.x, (int) (box.y + box.h/2) + Camera::pos.y, rotation);
}

bool Minion::IsDead(){
    return false;
}

void Minion::Shoot(Vec2 pos){
    Vec2 minionCenter(box.x + box.w, box.y + box.h);

    Bullet* minionBullet = new Bullet(minionCenter.x, minionCenter.y, minionCenter.ToAngle(pos), OBJECT_LINEAR_SPEED * 4 , minionCenter.Distance(pos), "./resources/img/minionbullet2.png", 0.2, 3, true);
    Game::GetInstance().GetState().AddObject(minionBullet);
}

void Minion::NotifyCollision(GameObject& other){
    if(other.Is("Bullet")){
        
    }
}

bool Minion::Is(std::string type){
    return (type == "Minion");
}