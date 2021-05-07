#pragma once

#include "State.h"

class LevelPrincipal : public State { 
private:
    MapaPrincipal *mapa;
    Espadachim *espadachim;
    Monstro *monstro;

    void initEntidade();
public:
    LevelPrincipal(sf::RenderWindow *window);
    ~LevelPrincipal();

    //Functions
    
    void updateColisao();
    void updateEntidade();
    void render(sf::RenderTarget&target);
};
