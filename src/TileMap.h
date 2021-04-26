#include <vector>
#include "Tile.h"
class TileMap
{
private:
    std::vector< std::vector <Tile *>> mapa;
    sf::Texture textura;
    int largura;//25
    int altura;//15

    void initTextura();
    void initVariaveis();
public:
    TileMap(/* args */);
    ~TileMap();
    void initTiles();
    void render(sf::RenderTarget&target);
};
