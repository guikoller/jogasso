#pragma once
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

class Entidade{
public:
    sf::Vector2f pos;
    sf::Sprite sprite;

    virtual void iniciaSprite()= 0;


    Entidade();
    virtual ~Entidade() = 0;

    virtual void update()= 0;
    virtual void render(sf::RenderTarget&target)= 0;
};

