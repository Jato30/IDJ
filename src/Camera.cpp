#include "Camera.hpp"

GameObject* Camera::focus = nullptr;
Vec2 Camera::pos = Vec2(0, 0);
Vec2 Camera::speed;

void Camera::Follow(GameObject* newFocus){
    focus = newFocus;
}

void Camera::UnFollow(){
    focus = nullptr;
}

void Camera::Update(float dt){
    if(focus != nullptr && focus->IsDead()){
        UnFollow();
    }
    if(INPUT_M.KeyPress(Y_KEY)){
        if(focus == nullptr){
            Follow(Penguins::player);
        }
        else{
            UnFollow();
        }
    }

    if(focus != nullptr){
        // Movimento acelerado, quanto mais longe do foco, mais rápido irá até ele
        speed.x += (CAMERA_SPEED / 4) * dt * std::cos(Vec2(pos.x, pos.y).ToAngle(Vec2(512 - focus->box.x - (focus->box.w / 2), 300 - focus->box.y - (focus->box.h / 2))));
        speed.y += (CAMERA_SPEED / 4) * dt * std::sin(Vec2(pos.x, pos.y).ToAngle(Vec2(512 - focus->box.x - (focus->box.w / 2), 300 - focus->box.y - (focus->box.h / 2))));

        if(((pos.x >= (512 - focus->box.x - focus->box.w)) && (pos.x <= (512 - focus->box.x + focus->box.w))) && ((pos.y >= (300 - focus->box.y - focus->box.h)) && (pos.y <= (300 - focus->box.y + focus->box.h)))){
            speed = 0;
            pos.x = 512 - focus->box.x - (focus->box.w / 2);
            pos.y = 300 - focus->box.y - (focus->box.h / 2);
        }
        
        pos.x += speed.x;
        pos.y += speed.y;

        // Se passar da posição, não pode entrar em órbita
        if(pos.x >= (512 - focus->box.x - focus->box.w)){
            if(pos.x <= (512 - focus->box.x + focus->box.w)){
                speed.x = 0;
                pos.x = 512 - focus->box.x - (focus->box.w / 2);
            }
        }
        if(pos.x <= (512 - focus->box.x + focus->box.w)){
            if(pos.x >= (512 - focus->box.x - focus->box.w)){
                speed.x = 0;
                pos.x = 512 - focus->box.x - (focus->box.w / 2);
            }
        }

        if(pos.y >= (300 - focus->box.y - focus->box.h)){
            if(pos.y <= (300 - focus->box.y + focus->box.h)){
                speed.y = 0;
                pos.y = 300 - focus->box.y - (focus->box.h / 2);
            }
        }
        if(pos.y <= (300 - focus->box.y + focus->box.h)){
            if(pos.y >= (300 - focus->box.y - focus->box.h)){
                speed.y = 0;
                pos.y = 300 - focus->box.y - (focus->box.h / 2);
            }
        }
    }
    
    else{
        if(INPUT_M.IsKeyDown(LEFT_ARROW_KEY)){
            speed.x = CAMERA_SPEED;
        }
        if(INPUT_M.IsKeyDown(UP_ARROW_KEY)){
            speed.y = CAMERA_SPEED;
        }
        if(INPUT_M.IsKeyDown(RIGHT_ARROW_KEY)){
            speed.x = CAMERA_SPEED * (-1);
        }
        if(INPUT_M.IsKeyDown(DOWN_ARROW_KEY)){
            speed.y = CAMERA_SPEED * (-1);
        }
        pos.x += speed.x * dt;
        pos.y += speed.y * dt;
        
        speed = 0;
    }
}