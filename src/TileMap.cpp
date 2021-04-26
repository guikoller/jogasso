#include "TileMap.h"

TileMap::TileMap(/* args */)
{
    this->gridTamU = 50;
    this->tamMax.x = 5000;
    this->tamMax.y = 5000;
    this->layers = 5;
    /*
    for (size_t x = 0; x < this->tamMax.x; x++)
    {
        this->mapa.push_back(std::vector< std::vector<Tile>>());
        
        for (size_t y = 0; y < tamMax.y; y++)
        {
            this->mapa[x].push_back(std::vector<Tile>());

            for (size_t z = 0; z < this->layers; z++)
            {
                this->mapa[x][y].push_back(Tile());
            }
            

        }
        
    }*/
    
    
}

TileMap::~TileMap()
{
}