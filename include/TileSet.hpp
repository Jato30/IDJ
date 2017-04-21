#ifndef _TILESET_HPP_
#define _TILESET_HPP_

#include <string>

class TileSet;

#include "Sprite.hpp"

class TileSet{
    private:
        Sprite tileSet;
        int rows;
        int columns;
        int tileWidth;
        int tileHeight;

    public:
        TileSet(int, int, std::string);
        void Render(unsigned int, float, float);
        int GetTileWidth();
        int GetTileHeight();
};

#include <vector>
#include "TileMap.hpp"

#endif // _TILESET_HPP_