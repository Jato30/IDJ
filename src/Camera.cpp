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
    if(focus != nullptr){
        // Fazer do centro da tela o foco
    }
    
    else{
        if(INPUT_M.IsKeyDown(LEFT_ARROW_KEY) || INPUT_M.IsKeyDown(A_KEY)){
            speed.x += CAMERA_SPEED;
        }
        if(INPUT_M.IsKeyDown(UP_ARROW_KEY) || INPUT_M.IsKeyDown(W_KEY)){
            speed.y += CAMERA_SPEED;
        }
        if(INPUT_M.IsKeyDown(RIGHT_ARROW_KEY) || INPUT_M.IsKeyDown(D_KEY)){
            speed.x += CAMERA_SPEED * (-1);
        }
        if(INPUT_M.IsKeyDown(DOWN_ARROW_KEY) || INPUT_M.IsKeyDown(S_KEY)){
            speed.y += CAMERA_SPEED * (-1);
        }
        pos.x += speed.x * dt;
        pos.y += speed.y * dt;
        speed.x = 0;
        speed.y = 0;
    }
}