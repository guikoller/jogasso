#pragma once
#include "Obstaculo.h"
class Porta : public Obstaculo{
private:
    void iniciaSprite();
public:
    Porta(/* args */);
    ~Porta();
    void update();
    void render(sf::RenderTarget&target);
};

