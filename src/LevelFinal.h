#pragma once

#include "LevelBase.h"
#include "Botao.h"

class LevelFinal : public LevelBase { 
private:
    Goblin *goblin;
    Lista<Inimigo> *listaInimigos;
    Inimigo *esqueleto;
    Inimigo *monstro;
    Obstaculo *espinho;
    Obstaculo *porta;
    Obstaculo *portal;

    float dt;
    std::map<std::string, Botao*> btns;

    void initEntidade();
public:
    LevelFinal(sf::RenderWindow *window, std::stack<State*>* states);
    ~LevelFinal();

    //Functions
    void initListaInimigo();
    void updateColisao();
    void updateEntidade();
    void render(sf::RenderTarget&target);
};
