#pragma once
#include <vector>
#include "Tile.h"
class TileMap
{
protected:
    std::vector< std::vector <Tile *>> mapa;
    sf::Texture textura;
    int largura;//25
    int altura;//15

    void initTextura();
    void initVariaveis();
public:
    TileMap(/* args */);
    virtual ~TileMap();

    //Acessores
    int getAltura();
    int getLargura();
    sf::Sprite getSprite(int x, int y);
    bool getSolido(int x, int y);
    
    virtual void desenhaMapa() = 0;
    void render(sf::RenderTarget&target);
};
