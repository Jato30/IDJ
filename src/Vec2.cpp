#include "Vec2.hpp"
#include "Game.hpp"

Vec2::Vec2(){
    x = 0;
    y = 0;
}

Vec2::Vec2(float posX, float posY){
    x = posX;
    y = posY;
}

void Vec2::operator=(Vec2 v){
    x = v.x;
    y = v.y;
}

void Vec2::operator+=(Vec2 v){
    x += v.x;
    y += v.y;
}

void Vec2::operator-=(Vec2 v){
    x -= v.x;
    y -= v.y;
}

void Vec2::operator*=(Vec2 v){
    x *= v.x;
    y *= v.y;
}

void Vec2::operator/=(Vec2 v){
    x /= v.x;
    y /= v.y;
}

float Vec2::Magnitude(){
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

void Vec2::operator=(float n){
    x = n;
    y = n;
}

void Vec2::operator+=(float n){
    x += n;
    y += n;
}

void Vec2::operator-=(float n){
    x -= n;
    y -= n;
}

void Vec2::operator*=(float n){
    x *= n;
    y *= n;
}

void Vec2::operator/=(float n){
    x /= n;
    y /= n;
}

Vec2 Vec2::Center(){
    Vec2 centro;

    centro.x = x / 2;
    centro.y = y / 2;
    return centro;
}

void Vec2::Unit(){
    x /= Magnitude();
    y /= Magnitude();
}

// Distância do Vec2 passado até THIS
float Vec2::Distance(Vec2 v){
    return std::sqrt(std::pow(v.x - x, 2) + std::pow(v.y - y, 2));
}

// Transforma THIS em sua porcentagem de inclinação: 0 para 90° e 1 para 0°
Vec2 Vec2::AngleX(Vec2 v){
    Vec2 angles(std::cos(ToAngle(v)), std::sin(ToAngle(v)));
    return angles;
}

// Retorna ângulo em Radianos referente à inclinação entre THIS e Vec2 em relação ao eixo X
float Vec2::ToAngle(Vec2 v){
    float teta = std::atan2((v.y - y), (v.x - x));
    return teta;
}