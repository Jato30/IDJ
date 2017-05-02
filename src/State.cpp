#include "State.hpp"

State::State() : bg("./resources/img/ocean.jpg"){
    tileSet = new TileSet(64, 64, std::string("./resources/img/tileset.png"));
    tileMap = new TileMap(std::string("./resources/map/tileMap.txt"), tileSet);
    Alien* alien = new Alien(512, 300, rand() % 10 + 1);
    objectArray.emplace_back(alien);
    Penguins* penguin = new Penguins(704, 640);
    objectArray.emplace_back(penguin);
    quitRequested = false;
    Camera::Follow(penguin);
}

State::~State(){
    objectArray.clear();
    delete tileMap;
}

void State::LoadAssets(){

}

void State::Update(float dt){
    Camera::Update(dt);

    if(QuitRequested() || INPUT_M.QuitRequested()){
        quitRequested = true;
    }

    if(INPUT_M.KeyPress(SPACE_KEY)){
        Alien* alien2 = new Alien(512 - Camera::pos.x, 300 - Camera::pos.y, rand() % 11);
        objectArray.emplace_back(alien2);
    }
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

void State::Render(){
    int layer = 0;

    bg.Render(0, 0); // Background
    tileMap->Render((int) Camera::pos.x * (layer + 1), (int) Camera::pos.y * (layer + 1), layer, layer); // Primeira camada, piso

    for(unsigned int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Render();
    }
    // TODAS AS OUTRAS RENDERIZAÇÕES VÃO AQUI
    
    layer++;
    // Vezes (layer + 1) para sofrer efeito PARALLAX Scrolling em cada camada
    tileMap->Render((int) Camera::pos.x * (layer + 1), (int) Camera::pos.y * (layer + 1), tileMap->GetDepth() - 1);
}

bool State::QuitRequested(){
    return quitRequested;
}

void State::AddObject(GameObject* ptr){
    objectArray.emplace_back(ptr);
}