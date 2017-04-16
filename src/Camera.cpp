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
        // Fazer do foco o centro da tela
    }
    else{
        if(INPUT_M.IsKeyDown(LEFT_ARROW_KEY) || INPUT_M.IsKeyDown(A_KEY)){
            speed.x = dt;
        }
        else if(INPUT_M.IsKeyDown(UP_ARROW_KEY) || INPUT_M.IsKeyDown(W_KEY)){
            speed.y = dt;
        }
        else if(INPUT_M.IsKeyDown(RIGHT_ARROW_KEY) || INPUT_M.IsKeyDown(D_KEY)){
            speed.x = dt * (-1);
        }
        else if(INPUT_M.IsKeyDown(DOWN_ARROW_KEY) || INPUT_M.IsKeyDown(S_KEY)){
            speed.y = dt * (-1);
        }
        else{
            speed.x = 0;
            speed.y = 0;
        }
        pos.x += speed.x * CAMERA_SPEED;
        pos.y += speed.y * CAMERA_SPEED;
    }
}