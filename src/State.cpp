#include "State.hpp"

State::State(){
    popRequested = false;
    quitRequested = false;
}

State::~State(){

}

bool State::PopRequested(){
    return popRequested;
}

bool State::QuitRequested(){
    return quitRequested;
}

void State::AddObject(GameObject* ptr){
    objectArray.emplace_back(ptr);
}

void State::UpdateArray(float dt){
    for(unsigned int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Update(dt);
    }

    unsigned int size = objectArray.size();
    for(unsigned int i = 0; i < size; i++){
        for(unsigned int j = i + 1; j < size; j++){
            if(Collision::IsColliding(objectArray[i]->box, objectArray[j]->box, objectArray[i]->rotation, objectArray[j]->rotation)){
                objectArray[j]->NotifyCollision(*objectArray[i]);
                objectArray[i]->NotifyCollision(*objectArray[j]);
            }
        }

    }
    for(int i = objectArray.size() - 1; i >= 0; i--){
        if(objectArray[i]->IsDead()){
            objectArray.erase(objectArray.begin() + i);
        }
    }
}

void State::RenderArray(){
    for(unsigned int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Render();
    }
}