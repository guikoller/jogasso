#pragma once
#include "Obstaculo.h"
class Espinho : public Obstaculo{
private:
    void iniciaSprite();
public:
    Espinho(/* args */);
    ~Espinho();
    void update();
    void render(sf::RenderTarget&target);
};

