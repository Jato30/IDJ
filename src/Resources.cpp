#include "Resources.hpp"

std::unordered_map<std::string, SDL_Texture*> Resources::imageTable{};

SDL_Texture* Resources::GetImage(std::string file){
    std::unordered_map<std::string, SDL_Texture*>::const_iterator item = imageTable.find(file);

    if(item == imageTable.end()){
        SDL_Texture* texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

        if(texture != nullptr){
            imageTable.emplace(file, texture);
            return texture;
        }
        else{
            return nullptr;
        }
    }
    return item->second;
}

void Resources::ClearImages(){
    imageTable.erase(imageTable.begin(), imageTable.end());
    imageTable.clear();
}