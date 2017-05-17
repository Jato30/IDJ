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
    if((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) || (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0)){
        printf("Erro na inicialização:  %s.\n", SDL_GetError());
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if((window == nullptr) || (renderer == nullptr)){
        printf("Erro ao criar o jogo:  %s.\n", SDL_GetError());
        exit(1);
    }
    
    if(Mix_Init(MIX_INIT_OGG) < 0){
        printf("Erro na inicialização:  %s.\n", SDL_GetError());
        exit(1);
    }

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0){
        printf("Erro na inicialização:  %s.\n", SDL_GetError());
        exit(1);
    }

    if(TTF_Init() != 0){
        printf("Erro na inicialização:  %s.\n", SDL_GetError());
        exit(1);
    }
    
    storedState = nullptr;
}

Game::~Game(){
    if(storedState != nullptr){
        delete storedState;
    }
    while(!stateStack.empty()){
        stateStack.pop();
    }
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}

Game& Game::GetInstance(){
    return *instance;
}

State& Game::GetCurrentState(){
    return *stateStack.top();
}

SDL_Renderer* Game::GetRenderer(){
    return renderer;
}

void Game::Run(){
    storedState->Render();
    storedState->Update(dt);
    stateStack.emplace(storedState);
    if(storedState == nullptr){
        exit(1);
    }
    storedState = nullptr;
    while(!(stateStack.top()->QuitRequested()) || !(stateStack.empty())){
        CalculateDeltaTime();
        INPUT_M.Update();
        stateStack.top()->Render();
        stateStack.top()->Update(dt);
        SDL_RenderPresent(renderer);
        
        if(stateStack.top()->QuitRequested()){
            while(!stateStack.empty()){
                stateStack.pop();
            }
            break;
        }

        if(stateStack.top()->PopRequested()){
            stateStack.pop();
            if(!stateStack.empty()){
                stateStack.top()->Resume();
            }
        }
        if(storedState != nullptr){
            if(!stateStack.empty()){
                stateStack.top()->Pause();
            }
            stateStack.emplace(storedState);
            storedState = nullptr;
        }

        SDL_Delay(33);
    }
    Resources::ClearImages();
    Resources::ClearMusics();
    Resources::ClearSounds();
    Resources::ClearFonts();
}

void Game::CalculateDeltaTime(){
    float newFrame = SDL_GetTicks();

    dt = (newFrame - frameStart) / 1000;
    frameStart = (float) newFrame;
}

float Game::GetDeltaTime(){
    return dt;
}

void Game::Push(State* state){
    storedState = state;
}