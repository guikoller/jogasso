#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

class Entidade{
protected:
    sf::Vector2f pos;
    sf::Sprite sprite;


    virtual void iniciaSprite();


public:
    Entidade();
    virtual ~Entidade();



    virtual void update();
    virtual void render(sf::RenderTarget&target);
};
