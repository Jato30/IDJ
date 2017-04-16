#include "TileSet.hpp"

TileSet::TileSet(int width, int height, std::string file){
    tileWidth = width;
    tileHeight = height;
    tileSet.Open(file);
    if(!tileSet.IsOpen()){
        printf("Impossível abrir o Tile.\n");
        exit(0);
    }
    rows = tileSet.GetWidth() / tileWidth;
    columns = tileSet.GetHeight() / tileHeight;
}

void TileSet::Render(unsigned int index, float x, float y){
    if(index < (rows * columns)){ // Quantidade de tiles

        int clipX = (index % rows) * tileWidth;
        int clipY = ((int)(index / rows)) * tileHeight;

        tileSet.SetClip(clipX, clipY, tileWidth, tileHeight);
        tileSet.Render(x, y);
    }
    else{
        printf("Algo de errado aconteceu com Tile.\n");
        exit(0);
    }
}

int TileSet::GetTileWidth(){
    return tileWidth;
}

int TileSet::GetTileHeight(){
    return tileHeight;
}