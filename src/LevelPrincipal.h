#pragma once
#include "LevelBase.h"
#include "Espadachim.h"
#include "MapaPrincipal.h"

class LevelPrincipal: public LevelBase{
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
    void render(sf::RenderTarget&target);
};
