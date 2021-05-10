#pragma once
#include "Obstaculo.h"
class Portal : public Obstaculo{
private:
    void iniciaSprite();
public:
    Portal(/* args */);
    ~Portal();
    void update();
    void render(sf::RenderTarget&target);
};

