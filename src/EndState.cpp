#include "EndState.hpp"

EndState::EndState(StateData stateData) : State(),
    bg((stateData.playerVictory) ? "./resources/img/win.jpg" : "./resources/img/lose.jpg"),
    music((stateData.playerVictory) ? "./resources/audio/endStateWin.ogg" : "./resources/audio/endStateLose.ogg"),
    instruction("./resources/font/Call me maybe.ttf", 36, Text::TextStyle::BLENDED, "ESC to main menu or Space bar to try again", Text::GetColor(Text::Colors::WHITE), new Timer()){

    instruction.SetPos(512, 30, true);
}

void EndState::Update(float dt){
    dt = dt;
    if(QuitRequested() || INPUT_M.QuitRequested()){
        quitRequested = true;
    }

    if(INPUT_M.KeyPress(ESC_KEY)){
        popRequested = true;
        TitleState* titleState = new TitleState();
        Game::GetInstance().Push(titleState);
    }

    if(INPUT_M.KeyPress(SPACE_KEY)){
        popRequested = true;
        StageState* stage = new StageState();
        Game::GetInstance().Push(stage);
    }
}

void EndState::Render(){
    bg.Render(0, 0);
    instruction.Render(0, 0);
}

void EndState::Pause(){

}

void EndState::Resume(){

}

void EndState::LoadAssets(){
    Resources::GetMusic("./resources/audio/endStateWin.ogg");
    Resources::GetMusic("./resources/audio/endStateLose.ogg");
    Resources::GetImage("./resources/img/win.jpg");
    Resources::GetImage("./resources/img/lose.jpg");
    Resources::GetFont("./resources/img/Call me maybe.ttf", 36);
}