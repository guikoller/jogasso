#pragma once

#include "LevelBase.h"

class LevelPrincipal : public LevelBase { 
private:

    Lista<Inimigo> *listaInimigos;
    Lista<Esqueleto> *listaEsqueletos;
    Inimigo *monstro;
    Inimigo *esqueleto;
    Obstaculo *porta;
    Obstaculo *caixa[5];
    Obstaculo *espinho[5];


    void initEntidade();
public:
    LevelPrincipal(sf::RenderWindow *window, std::stack<State*>* states);
    ~LevelPrincipal();

    //Functions
    void initPosInimigo();
    void initListaInimigo();
    void updateColisao();
    void updateEntidade();
    //void update();
    void render(sf::RenderTarget&target);
};
