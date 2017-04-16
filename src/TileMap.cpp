#include "TileMap.hpp"

TileMap::TileMap(std::string file, TileSet* tileSet) : tileMatrix(){
    Load(file);
    SetTileSet(tileSet);
}

void TileMap::Load(std::string file){ // file é o caminho do arquivo
    int val; // Auxiliar para pegar os valores do arquivo .txt

    // Abrir arquivo no tipo que permite apenas leitura
    std::FILE* fp = fopen(file.c_str(), "r");
    if(!fp){
        std::perror("Falha ao abrir o arquivo.\n");
        exit(0);
    }

    fscanf(fp, "%d,%d,%d, ", &mapWidth, &mapHeight, &mapDepth);

    int qtd = mapWidth * mapHeight; // Quantidade de indices lineares / mapDepth
    tileMatrix.resize(qtd * mapDepth); // Define o tamanho para não estourar ou sobrar espaço
    
    for(int j = 0; j < mapDepth; j++){
        for(int i = 0; i < qtd; i++){
            fscanf(fp, " %d, ", &val);
            tileMatrix[i + j * qtd] = val - 1; // mudei o acesso a matrix
        }
    }


/*
    std::fstream fp.open(file, std::fstream::in | std::fstream::out | std::fstream::app);
    if(!fp.IsOpen()){
        exist(0);
    }
    char ch1 = NULL, ch2 = NULL, ch3 = NULL;
    int qtd = 100;
    bool colocou = false;
    while(fp.get(ch1)){

        }
    }
*/

}

void TileMap::SetTileSet(TileSet* tileSet){
    this->tileSet = tileSet;
}

int& TileMap::At(int x, int y, int z){
    return tileMatrix[((mapWidth * mapHeight * z) + (y * mapWidth) + (x))];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
    int i, j, indexAux;

    for(j = 0; j < mapHeight; j++){
        for(i = 0; i < mapWidth; i++){ // Inverti a ordem com o de cima
            /*int rows = tileSet->tileSet.GetWidth() / tileSet->GetTileWidth();
            int columns = tileSet->tileSet.GetHeight() / tileSet->GetTileHeight();
            if(rows > 3 && columns < 2){
                layer = mapDepth - 1;
            }*/

            // Impedir que a câmera fuja para longe do mapa
            /*if(Camera::pos.x > mapWidth + 1000){
                Camera::pos.x = mapWidth + 1000;
            }
            if(Camera::pos.x < -mapWidth - 1500){
                Camera::pos.x = -mapWidth - 1500;
            }
            if(Camera::pos.y > mapHeight + 500){
                Camera::pos.y = mapHeight + 500;
            }
            if(Camera::pos.y < -mapHeight - 1500){
                Camera::pos.y = -mapHeight - 1500;
            }*/
            indexAux = At(i, j, layer);
            if(indexAux >= 0){
                tileSet->Render(indexAux, (cameraX + (i * tileSet->GetTileWidth())), (cameraY + (j * tileSet->GetTileHeight())));
            }
        }
    }
}

void TileMap::Render(int cameraX, int cameraY, int layer){
    //for(int i = 0; i < mapDepth; i++){
        // Para não renderizar todo o MAP de uma vez, mas só a camada que eu quero
        RenderLayer(layer, cameraX, cameraY);
    //}
}

int TileMap::GetWidth(){
    return mapWidth;
}

int TileMap::GetHeight(){
    return mapHeight;
}

int TileMap::GetDepth(){
    return mapDepth;
}