#include <vector>
#include "Tile.h"
class TileMap
{
private:
    unsigned gridTamU;
    sf::Vector2u tamMax;
    unsigned layers;
    //vetor de vetores de vetores de vetores de tile
    std::vector < std::vector < std::vector < Tile > > > mapa;

public:
    TileMap(/* args */);
    ~TileMap();
};
