#pragma once

#include "LevelBase.h"
#include "Botao.h"

class LevelFinal : public LevelBase { 
private:
    Goblin *goblin;
    Obstaculo *caixa;
    Obstaculo *espinho;
    Obstaculo *porta;

    sf::Clock tempo;
    float dt;
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
