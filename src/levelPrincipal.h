#pragma once
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Espadachim.h"
#include "MapaPrincipal.h"

class levelPrincipal{
    MapaPrincipal *mapa;
    Espadachim * espadachim;
    void initEntidade();
public:
    levelPrincipal(/* args */);
    ~levelPrincipal();
    //Functions

    void updateColisao();
    void updateEntidade();
    void update();
    void render(sf::RenderTarget&target);
};
