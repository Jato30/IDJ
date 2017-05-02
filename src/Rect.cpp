#include "Rect.hpp"

Rect::Rect(){

}

Rect::Rect(float coordX, float coordY, float width, float height){
    x = coordX;
    y = coordY;
    w = width;
    h = height;
}

bool Rect::IsInside(float mouseX, float mouseY){
    return ((mouseX >= x) && (mouseX <= (x + w)) && (mouseY >= y) && (mouseY <= (y + h)));
}

Vec2 Rect::GetCenter(){
    return Vec2(x + (w /2 ), y + (h / 2));
}