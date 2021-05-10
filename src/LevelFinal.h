#pragma once

#include "LevelBase.h"
#include "Botao.h"

class LevelFinal : public LevelBase { 
private:
    Goblin *inimigo;
    Obstaculo *caixa;
    Obstaculo *espinho;
    Obstaculo *porta;
    Obstaculo *portal;

    std::map<std::string, Botao*> btns;

    void initEntidade();
public:
    LevelFinal(sf::RenderWindow *window, std::stack<State*>* states);
    ~LevelFinal();

    //Functions
    
    void updateColisao();
    void updateEntidade();
    void render(sf::RenderTarget&target);
};
