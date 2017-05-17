#include "Resources.hpp"

std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> Resources::imageTable{};
std::unordered_map<std::string, std::shared_ptr<Mix_Music>> Resources::musicTable{};
std::unordered_map<std::string, std::shared_ptr<Mix_Chunk>> Resources::soundTable{};
std::unordered_map<std::string, std::shared_ptr<TTF_Font>> Resources::fontTable{};


std::shared_ptr<SDL_Texture> Resources::GetImage(std::string file){
    std::unordered_map<std::string, std::shared_ptr<SDL_Texture>>::const_iterator item = imageTable.find(file);

    if(item == imageTable.end()){
        SDL_Texture* texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

        if(texture != nullptr){
            //imageTable[file]= ptr;
            imageTable.emplace(file,
                                std::shared_ptr<SDL_Texture> (texture,
                                                                    [](SDL_Texture* texture){
                                                                        SDL_DestroyTexture(texture);
                                                                    }

                                                                )
                            );

            return imageTable[file];
        }
        else{
            return nullptr;
        }
    }
    return item->second;
}

void Resources::ClearImages(){
    for(auto it = imageTable.begin(); it != imageTable.end(); ){
        if(it->second.unique()){
            it = imageTable.erase(it);
        }
        else{
            it++;
        }
    }

    if(imageTable.empty()){
        imageTable.clear();
    }
}


std::shared_ptr<Mix_Music> Resources::GetMusic(std::string file){
    std::unordered_map<std::string, std::shared_ptr<Mix_Music>>::const_iterator item = musicTable.find(file);

    if(item == musicTable.end()){
        Mix_Music* music = Mix_LoadMUS(file.c_str());

        if(music != nullptr){
            musicTable.emplace(file,
                                std::shared_ptr<Mix_Music> (music,
                                                                [](Mix_Music* music){
                                                                    Mix_FreeMusic(music);
                                                                }
                                                            )
                            );

            return musicTable[file];
        }
        else{
            return nullptr;
        }
    }

    return item->second;
}

void Resources::ClearMusics(){
    for(auto it = musicTable.begin(); it != musicTable.end(); ){
        if(it->second.unique()){
            it = musicTable.erase(it);
        }
        else{
            it++;
        }
    }

    if(musicTable.empty()){
        musicTable.clear();
    }
}


std::shared_ptr<Mix_Chunk> Resources::GetSound(std::string file){
    std::unordered_map<std::string, std::shared_ptr<Mix_Chunk>>::const_iterator item = soundTable.find(file);

    if(item == soundTable.end()){
        Mix_Chunk* chunk = Mix_LoadWAV(file.c_str());

        if(chunk != nullptr){
            soundTable.emplace(file,
                                std::shared_ptr<Mix_Chunk> (chunk,
                                                                [](Mix_Chunk* chunk){
                                                                    Mix_FreeChunk(chunk);
                                                                }
                                                            )
                            );

            return soundTable[file];
        }
        else{
            return nullptr;
        }
    }

    return item->second;
}

void Resources::ClearSounds(){
    for(auto it = soundTable.begin(); it != soundTable.end(); ){
        if(it->second.unique()){
            it = soundTable.erase(it);
        }
        else{
            it++;
        }
    }

    if(soundTable.empty()){
        soundTable.clear();
    }
}


std::shared_ptr<TTF_Font> Resources::GetFont(std::string file, int size){
    std::unordered_map<std::string, std::shared_ptr<TTF_Font>>::const_iterator item = fontTable.find(file + std::to_string(size));

    if(item == fontTable.end()){
        TTF_Font* font = TTF_OpenFont(file.c_str(), size);

        if(font != nullptr){
            fontTable.emplace(file,
                                std::shared_ptr<TTF_Font> (font,
                                                                [](TTF_Font* font){
                                                                    TTF_CloseFont(font);
                                                                }
                                                            )
                            );

            return fontTable[file];
        }
        else{
            return nullptr;
        }
    }

    return item->second;
}

void Resources::ClearFonts(){
    for(auto it = fontTable.begin(); it != fontTable.end(); ){
        if(it->second.unique()){
            it = fontTable.erase(it);
        }
        else{
            it++;
        }
    }

    if(fontTable.empty()){
        fontTable.clear();
    }
}