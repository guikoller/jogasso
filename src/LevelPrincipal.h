#pragma once
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Espadachim.h"
#include "MapaPrincipal.h"

class LevelPrincipal{
private:
    MapaPrincipal *mapa;
    Espadachim * espadachim;
    void initEntidade();
public:
    LevelPrincipal(/* args */);
    ~LevelPrincipal();

    //Functions
    void updateColisao();
    void updateEntidade();
    void update();
    void render(sf::RenderTarget&target);
};
