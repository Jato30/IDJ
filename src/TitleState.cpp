#include "TitleState.hpp"

TitleState::TitleState() : State(), bg("./resources/img/title.jpg"){
    pressSpace = new Text("./resources/font/Call me maybe.ttf", 36, Text::TextStyle::SOLID, "Press SPACE button to start", Text::GetColor(Text::Colors::BLACK), new Timer());
    pressSpace->SetPos(512, 500, true);
}

void TitleState::Update(float dt){
    dt = dt;
    if(QuitRequested() || INPUT_M.QuitRequested() || INPUT_M.KeyPress(ESC_KEY)){
        quitRequested = true;
    }

    pressSpace->Render();

    if(INPUT_M.KeyPress(SPACE_KEY)){
        popRequested = true;
        StageState* stageState = new StageState();
        Game::GetInstance().Push(stageState);
    }
}

void TitleState::Render(){
    bg.Render(0, 0);
}

void TitleState::LoadAssets(){
    Resources::GetImage("./resources/img/title.jpg");
    Resources::GetFont("./resources/font/Call me maybe.ttf", 36);
}

void TitleState::Pause(){

}

void TitleState::Resume(){

}