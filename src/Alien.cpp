#include "Alien.hpp"
#include "Game.hpp"

Alien::Alien(float x, float y, int nMinions) : GameObject(), sp("./img/alien.png"){
    box = Rect(x, y, sp.GetWidth(), sp.GetHeight());
    hp = 50;
    speed = Vec2(0, 0);
    if(nMinions > 0){
        for(int i = 0; i < nMinions; i++){
            minionArray.emplace_back(this, (float) (M_PI * i * (2 / (float) nMinions)));
        }
    }
    rotation = 2 * M_PI;
}

Alien::~Alien(){

}

void Alien::Update(float dt){
    rotation -= M_PI / 360;
    if(rotation <= 0){
        rotation = 2 * M_PI;
    }

    for(unsigned int i = 0; i < minionArray.size(); i++){
        minionArray[i].Update(dt);
        //minionArray[i].Render();
    }
    
    // Atirar
    if(INPUT_M.MousePress(LEFT_MOUSE_BUTTON)){
        Action actionL = Action(Action::ActionType::SHOOT, INPUT_M.GetMouseX() - Camera::pos.x, INPUT_M.GetMouseY() - Camera::pos.y);

        taskQueue.push(actionL);
    }
    
    // Mover-se
    if(INPUT_M.MousePress(RIGHT_MOUSE_BUTTON)){
        Action actionR = Action(Action::ActionType::MOVE, INPUT_M.GetMouseX() - Camera::pos.x, INPUT_M.GetMouseY() - Camera::pos.y);

        taskQueue.push(actionR);
    }

    if(!taskQueue.empty()){
        Vec2 alienMid = Vec2(box.x + box.w / 2, box.y + box.h / 2); // Posição do centro do Alien

        if(taskQueue.back().type == Action::SHOOT){
            if(minionArray.size() > 0){

                // Minion mais próximo do destino do tiro
                int closestIndex = 0;
                Vec2 posClosest(minionArray[closestIndex].box.x, minionArray[closestIndex].box.y);
                float closestDistance = posClosest.Distance(taskQueue.back().pos);
                for(unsigned int i = 0; i < minionArray.size(); i++){
                    posClosest = Vec2(minionArray[i].box.x, minionArray[i].box.y);
                    if(posClosest.Distance(taskQueue.back().pos) < closestDistance){
                        closestDistance = posClosest.Distance(taskQueue.back().pos);
                        closestIndex = i;
                    }
                }

                minionArray[closestIndex].Shoot(taskQueue.back().pos);
            }
            taskQueue.pop();
        }

        if(taskQueue.back().type == Action::MOVE){
            // Calcula velocidade de módulo constante e linha reta ao destino
            speed = (OBJECT_SPEED * dt);
            speed *= alienMid.AngleX(taskQueue.back().pos);

            // Se chegou ao destino
            if((taskQueue.back().pos.x > alienMid.x + speed.x && taskQueue.back().pos.x < alienMid.x - speed.x) || (taskQueue.back().pos.y > alienMid.y + speed.y && taskQueue.back().pos.y < alienMid.y - speed.y)){
            //if(box.IsInside(taskQueue.back().pos.x, taskQueue.back().pos.y)){
                speed = 0;
                taskQueue.pop();
            }
            else{
                box.x += speed.x;
                box.y += speed.y;
            }
        }
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

Alien::Action::Action(ActionType at, float x, float y){
    type = at;
    pos.x = x;
    pos.y = y;
}