#pragma once

#include "State.h"

class LevelFinal : public State { 
private:
    MapaPrincipal *mapa;
    Espadachim *espadachim;

    void initEntidade();
public:
    LevelFinal(sf::RenderWindow *window);
    ~LevelFinal();

    //Functions
    
    void updateColisao();
    void updateEntidade();
    void render(sf::RenderTarget&target);
};
