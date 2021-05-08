#pragma once

#include "State.h"

class LevelPrincipal : public State { 
private:
    MapaPrincipal *mapa;
    Espadachim *espadachim;
    Inimigo *monstro;
    Inimigo *esqueleto;
    

    void initEntidade();
public:
    LevelPrincipal(sf::RenderWindow *window);
    ~LevelPrincipal();

    //Functions
    
    void updateColisao();
    void updateEntidade();
    void update();
    void render(sf::RenderTarget&target);
};
