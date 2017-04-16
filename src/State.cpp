#include "State.hpp"

State::State() : bg("./resources/img/ocean.jpg"){
    tileSet = new TileSet(64, 64, std::string("./resources/img/tileset.png"));
    tileMap = new TileMap(std::string("./resources/map/tileMap.txt"), tileSet);
    quitRequested = false;
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
        AddObject((float) INPUT_M.GetMouseX(), (float) INPUT_M.GetMouseY());
    }
    for(int i = objectArray.size() -1; i >= 0; i--){
        objectArray[i]->Update(dt);
        if(objectArray[i]->IsDead()){
            objectArray.erase(objectArray.begin() + i);
        }
    }
}

void State::Render(){
    bg.Render(0, 0);
    tileMap->Render((int) Camera::pos.x, (int) Camera::pos.y);
    for(unsigned int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Render();
    }
    // TODAS AS OUTRAS RENDERIZAÇÕES VÃO AQUI
    tileMap->Render((int) Camera::pos.x * 2, (int) Camera::pos.y * 2, 1); // Vezes 2 para sofrer efeito PARALLAX
}

bool State::QuitRequested(){
    return quitRequested;
}

void State::AddObject(float mouseX, float mouseY){
    float aux = (float) (rand() % 2000);
    double random = (aux / 1000) * M_PI;
    
    Face* face = new Face(mouseX - Camera::pos.x + (200 * cos(random)), mouseY - Camera::pos.y + (200 * sin(random)));
    objectArray.emplace_back(face);
}