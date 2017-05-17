#include "StageState.hpp"

StageState::StageState() : State(), bg("./resources/img/ocean.jpg"){
    tileSet = new TileSet(64, 64, std::string("./resources/img/tileset.png"));
    tileMap = new TileMap(std::string("./resources/map/tileMap.txt"), tileSet);
    bgSong = Music("./resources/audio/stageState.ogg");
    toEnd = Timer();
    alienRespawn = Timer();
    
    Penguins* penguin = new Penguins(704, 640);
    AddObject(penguin);

    for(int i = 0; i < 4; i++){
        Alien* alien = new Alien(rand() % 1408, rand() % 1280, rand() % 10 + 1);
        while(alien->box.IsInside(penguin->box.x - 30, penguin->box.y - 30) || alien->box.IsInside(penguin->box.x + penguin->box.w + 30, penguin->box.y - 30) || alien->box.IsInside(penguin->box.x - 30, penguin->box.y + penguin->box.h + 30) || alien->box.IsInside(penguin->box.x + penguin->box.w + 30, penguin->box.y + penguin->box.h + 30)){
            alien->box.x = rand() % 1408;
            alien->box.y = rand() % 1280;
        }
        AddObject(alien);
    }

    quitRequested = false;
    Camera::Follow(penguin);
    bgSong.Play(-1);
}

StageState::~StageState(){
    objectArray.clear();
    delete tileMap;
}

void StageState::Update(float dt){
    Camera::Update(dt);
    UpdateArray(dt);
    toEnd.Update(dt);
    alienRespawn.Update(dt);

    if(QuitRequested() || INPUT_M.QuitRequested()){
        bgSong.Stop();
        quitRequested = true;
    }

    if(INPUT_M.KeyPress(ESC_KEY)){
        bgSong.Stop();
        popRequested = true;
        TitleState* titleState = new TitleState();
        Game::GetInstance().Push(titleState);
    }

    if(Penguins::player == nullptr || Alien::alienCount == 0){
        if(toEnd.Get() > 1.5){
            toEnd.Restart();
        }

        else if(toEnd.Get() >= 0.75){
            bgSong.Stop();
            popRequested = true;
            StateData data = StateData();
            data.playerVictory = Alien::alienCount == 0 ? true : false;
            EndState* endState = new EndState(data);
            Game::GetInstance().Push(endState);
        }
    }

    if(alienRespawn.Get() >= 20){
        Alien* alien = new Alien(rand() % 1408, rand() % 1280, rand() % 10 + 1);
        while(alien->box.IsInside(Penguins::player->box.x - 30, Penguins::player->box.y - 30) || alien->box.IsInside(Penguins::player->box.x + Penguins::player->box.w + 30, Penguins::player->box.y - 30) || alien->box.IsInside(Penguins::player->box.x - 30, Penguins::player->box.y + Penguins::player->box.h + 30) || alien->box.IsInside(Penguins::player->box.x + Penguins::player->box.w + 30, Penguins::player->box.y + Penguins::player->box.h + 30)){
            alien->box.x = rand() % 1408;
            alien->box.y = rand() % 1280;
        }
        AddObject(alien);
        alienRespawn.Restart();
    }
}

void StageState::Render(){
    int layer = 0;

    bg.Render(0, 0); // Background
    tileMap->Render((int) Camera::pos.x * (layer + 1), (int) Camera::pos.y * (layer + 1), layer, layer); // Primeira camada, piso

    RenderArray();
    // TODAS AS OUTRAS RENDERIZAÇÕES VÃO AQUI
    
    layer++;
    // Vezes (layer + 1) para sofrer efeito PARALLAX Scrolling em cada camada
    tileMap->Render((int) Camera::pos.x * (layer + 1), (int) Camera::pos.y * (layer + 1), tileMap->GetDepth() - 1);
}

void StageState::LoadAssets(){
    Resources::GetMusic("./resources/audio/stageState.ogg");
    Resources::GetMusic("./resources/audio/boom.wav");
    Resources::GetImage("./resources/img/ocean.jpg");
    Resources::GetImage("./resources/map/tileMap.txt");
    Resources::GetImage("./resources/img/tileset.png");
    Resources::GetImage("./resources/img/alien.png");
    Resources::GetImage("./resources/img/minion.png");
    Resources::GetImage("./resources/img/minionbullet2.png");
    Resources::GetImage("./resources/img/penguin.png");
    Resources::GetImage("./resources/img/cubngun.png");
    Resources::GetImage("./resources/img/penguinbullet.png");
    Resources::GetImage("./resources/img/aliendeath.png");
    Resources::GetImage("./resources/img/miniondeath.png");
    Resources::GetImage("./resources/img/penguindeath.png");
}

void StageState::Pause(){

}

void StageState::Resume(){
    
}