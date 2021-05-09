#pragma once
#include "Obstaculo.h"
class Caixa : public Obstaculo{
private:
    void iniciaSprite();
public:
    Caixa(/* args */);
    ~Caixa();
    void update();
    void render(sf::RenderTarget&target);
};

