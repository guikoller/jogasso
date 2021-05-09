#pragma once

#include "LevelBase.h"
#include "Botao.h"

class LevelFinal : public LevelBase { 
private:
    Inimigo *inimigo;

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
