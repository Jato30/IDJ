#include "Alien.hpp"
#include "Game.hpp"

int Alien::alienCount = 0;

Alien::Alien(float x, float y, int nMinions) : GameObject(), sp("./resources/img/alien.png"){
    alienCount++;
    box = Rect(x, y, sp.GetWidth(), sp.GetHeight());
    hp = 50;
    speed = Vec2(0.0, 0.0);
    if(nMinions > 0){
        for(int i = 0; i < nMinions; i++){
            minionArray.emplace_back(this, (float) (M_PI * i * (2 / (float) nMinions)));
        }
    }
    rotation = 2 * M_PI;
    state = RESTING;
    destination = Vec2();
    restTimer = Timer();
    shootCooldown = Timer();
}

Alien::~Alien(){
    alienCount--;
}

void Alien::Update(float dt){
    shootCooldown.Update(dt);

    if(Penguins::player != nullptr){
        switch(state){
            case RESTING:
                if(shootCooldown.Get() > 0.3){
                    shootCooldown.Restart();

                    if(minionArray.size() > 0){
                        // Minion mais próximo do destino do tiro
                        int closestIndex = 0;
                        Vec2 posClosest = minionArray[closestIndex].box.GetCenter();
                        float closestDistance = posClosest.Distance(Penguins::player->box.GetCenter());
                        for(unsigned int i = 0; i < minionArray.size(); i++){
                            posClosest = minionArray[i].box.GetCenter();
                            if(posClosest.Distance(Penguins::player->box.GetCenter()) <= closestDistance){
                                closestDistance = posClosest.Distance(Penguins::player->box.GetCenter());
                                closestIndex = i;
                            }
                        }
                        minionArray[closestIndex].Shoot(Penguins::player->box.GetCenter());
                    }
                }

                restTimer.Update(dt);
                if(restTimer.Get() >= 0.76 + ((rand() % 75) / 100)){
                    destination = Penguins::player->box.GetCenter();
                    // Calcula velocidade de módulo constante e linha reta ao destino
                    state = MOVING;
                }
                break;
            
            case MOVING:
                // Se chegou ao destino
                if(box.GetCenter().NearBy(destination)){
                    speed = 0;
                    state = RESTING;
                    restTimer.Restart();
                }
                speed = (OBJECT_LINEAR_SPEED * dt);
                speed *= box.GetCenter().AngleX(destination);
                box.x += speed.x;
                box.y += speed.y;
                break;
        }
    }

    rotation -= M_PI / 360;
    if(rotation <= 0){
        rotation = 2 * M_PI;
    }

    for(unsigned int i = 0; i < minionArray.size(); i++){
        minionArray[i].Update(dt);
    }
    
}

void Alien::Render(){
    sp.Render((int) box.x + Camera::pos.x, (int) box.y + Camera::pos.y, rotation);
    for(unsigned int i = 0; i < minionArray.size(); i++){
        minionArray[i].Render();
    }
}

bool Alien::IsDead(){
    return hp <= 0;
}

void Alien::NotifyCollision(GameObject& other){
    if(other.Is("Bullet")){
        if(!((Bullet&) other).targetsPlayer){
            hp -= 10;
        }
    }
    if(other.Is("Penguins")){
        hp -= 2;
    }
    if(hp <= 0){
        Animation* alienAnimation = new Animation(box.x, box.y, rotation, "./resources/img/aliendeath.png", 4, 0.1, true);
        Game::GetInstance().GetState().AddObject(alienAnimation);
        Animation* minionAnimation;
        for(unsigned int i = 0; i < minionArray.size(); i++){
            minionAnimation = new Animation(minionArray[i].box.x, minionArray[i].box.y, minionArray[i].rotation, "./resources/img/miniondeath.png", 4, 0.1, true);
            Game::GetInstance().GetState().AddObject(minionAnimation);
        }
    }
}

bool Alien::Is(std::string type){
    return (type == "Alien");
}