#include "Music.hpp"

Music::Music(){
    music = nullptr;
}

Music::Music(std::string file){
    Open(file);
}

void Music::Play(int times){
    Mix_PlayMusic(music.get(), times);
}

void Music::Stop(){
    Mix_FadeOutMusic(200);
}

void Music::Open(std::string file){
    music = Resources::GetMusic(file);

    if(music.get() == nullptr){
        printf("Impossível carregar música: %s", SDL_GetError());
        exit(0);
    }
}

bool Music::IsOpen(){
    return music != nullptr;
}