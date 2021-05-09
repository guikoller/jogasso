#pragma once

#include "LevelBase.h"

class LevelPrincipal : public LevelBase { 
private:

    Lista<Inimigo> *listaInimigos;
    Lista<Esqueleto> *listaEsqueletos;
    Inimigo *monstro;
    Inimigo *esqueleto;
    

    void initEntidade();
public:
    LevelPrincipal(sf::RenderWindow *window, std::stack<State*>* states);
    ~LevelPrincipal();

    //Functions
    void initListaInimigo();
    void updateColisao();
    void updateEntidade();
    //void update();
    void render(sf::RenderTarget&target);
};
