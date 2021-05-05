#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Colisor.h"

class Tile{
public:
    sf::Sprite sprite;
    sf::Vector2f pos;
    bool dano;
    bool solido;
    sf::RectangleShape hitBox;

    Tile(sf::Texture& texture, sf::IntRect texture_rect,float x, float y, bool dano, bool s);
    Tile();
    ~Tile();
    void initTextura();
    const sf::FloatRect getGlobalBounds()const;
    Colisor getColisao();
    void update();
    void render(sf::RenderTarget&target);
};