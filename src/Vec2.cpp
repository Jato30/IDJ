#include "Vec2.hpp"

Vec2::Vec2(){
    x = 0;
    y = 0;
}

Vec2::Vec2(float posX, float posY){
    x = posX;
    y = posY;
}

void Vec2::operator+(Vec2 v){
    x += v.x;
    y += v.y;
}

void Vec2::operator-(Vec2 v){
    x -= v.x;
    y -= v.y;
}

void Vec2::operator*(Vec2 v){
    x *= v.x;
    y *= v.y;
}

void Vec2::operator/(Vec2 v){
    x /= v.x;
    y /= v.y;
}

float Vec2::Magnitude(){
    return sqrt(pow(x, 2) + pow(y, 2));
}

void Vec2::Soma(float n){
    x += n;
    y += n;
}

void Vec2::Subtrai(float n){
    x -= n;
    y -= n;
}

void Vec2::Multiplica(float n){
    x *= n;
    y *= n;
}

void Vec2::Divide(float n){
    x /= n;
    y /= n;
}

Vec2 Vec2::Centro(){
    Vec2 centro;

    centro.x = x / 2;
    centro.y = y / 2;
    return centro;
}

void Vec2::Unit(){
    x /= Magnitude();
    y /= Magnitude();
}

float Vec2::Distancia(Vec2 v){
    return sqrt(pow(x - v.x, 2) + pow(y - v.y, 2));
}