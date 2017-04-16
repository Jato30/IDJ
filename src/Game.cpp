#include "Game.hpp"

Game* Game::instance = nullptr; // Por ser static

Game::Game(std::string title, int width, int height){
    frameStart = SDL_GetTicks();
    dt = 0;

    if(instance != nullptr){
        exit(1); // há um problema na lógica do seu jogo
    }
    else{
        instance = this;
    }

    // Se entrar: Erro irrecuperável ao inicializar
    // Se passar: criou tudo corretamente
    if((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) ||
    (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0)){
        printf("Erro na inicialização:  %s.\n", SDL_GetError());
    }
    
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if((window == nullptr) || (renderer == nullptr)){
        printf("Erro ao criar o jogo:  %s.\n", SDL_GetError());
        exit(1);
    }
    
    state = new State();
}

Game::~Game(){
    delete state;
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

Game& Game::GetInstance(){
    return *instance;
}

State& Game::GetState(){
    return *state;
}

SDL_Renderer* Game::GetRenderer(){
    return renderer;
}

void Game::Run(){
    while(!(state->QuitRequested())){
        CalculateDeltaTime();
        INPUT_M.Update();
        state->Update(dt);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
    Resources::ClearImages();
}

void Game::CalculateDeltaTime(){
    Uint32 newFrame = SDL_GetTicks();

    dt = (float) (newFrame - frameStart) / 1000;
    frameStart = (float) newFrame;
}

float Game::GetDeltaTime(){
    return dt;
}