#ifndef _TILEMAP_HPP_
#define _TILEMAP_HPP_

#include <vector>
#include <string>

class TileMap;

#include "TileSet.hpp"

class TileMap{
    private:
        std::vector<int> tileMatrix;
        TileSet* tileSet;
        int mapWidth;
        int mapHeight;
        int mapDepth;

    public:
        TileMap(std::string, TileSet*);
        void Load(std::string);
        void SetTileSet(TileSet*);
        int& At(int, int, int = 0);
        void Render(int = 0, int = 0, int = 0, unsigned int = -1);
        void RenderLayer(int, int = 0, int = 0);
        int GetWidth();
        int GetHeight();
        int GetDepth();
};

#include <cstdio>
#include "Sprite.hpp"
#include "Camera.hpp"

#endif // _TILEMAP_HPP_