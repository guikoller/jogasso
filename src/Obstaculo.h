#pragma once
#include "Entidade.h"

class Obstaculo : public Entidade{
protected:
    sf::Texture textura;
public:
    Obstaculo(/* args */);
    ~Obstaculo();
};

    
    