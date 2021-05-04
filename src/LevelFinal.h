#pragma once
#include "LevelBase.h"
#include "Espadachim.h"
#include "MapaPrincipal.h"

class LevelFinal: public LevelBase{
private:
    MapaPrincipal *mapa;
    Espadachim *espadachim;

    void initEntidade();
public:
    LevelFinal(/* args */);
    ~LevelFinal();

    //Functions
    void updateColisao();
    void updateEntidade();
    void render(sf::RenderTarget&target);
};
