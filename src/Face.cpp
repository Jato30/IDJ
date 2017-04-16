#include "Face.hpp"

Face::Face(float x, float y) : GameObject(), sp("./img/penguinface.jpg"){
    hitpoints = 30;
    box = Rect(x - (sp.GetWidth() / 2), y - (sp.GetHeight() / 2), sp.GetWidth(), sp.GetHeight());
}

void Face::Damage(int damage){
    hitpoints -= damage;
}

void Face::Update(float dt){
    if(INPUT_M.MousePress(LEFT_MOUSE_BUTTON) && box.IsInside((float) INPUT_M.GetMouseX() - Camera::pos.x, (float) INPUT_M.GetMouseY() - Camera::pos.y)){
        Damage(rand() % 10 + 10);
    }
}

void Face::Render(){
    sp.Render(box.x + Camera::pos.x, box.y + Camera::pos.y);
}

bool Face::IsDead(){
    return hitpoints <= 0;
}