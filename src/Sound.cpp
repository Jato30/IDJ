#include "Sound.hpp"

Sound::Sound(){
    chunk = nullptr;
}

Sound::Sound(std::string file){
    Open(file);
}

void Sound::Play(int times){
    channel = Mix_PlayChannel(-1, chunk.get(), times);
}

void Sound::Stop(){
    Mix_HaltChannel(channel);
}

void Sound::Open(std::string file){
    chunk = Resources::GetSound(file);

    if(chunk.get() == nullptr){
        printf("Impossível carregar som: %s", SDL_GetError());
        exit(0);
    }
}