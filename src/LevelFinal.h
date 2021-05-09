#pragma once

#include "LevelBase.h"
#include "Botao.h"

class LevelFinal : public LevelBase { 
private:
    Espadachim *espadachim;
    Inimigo *inimigo;

    void initEntidade();


    std::map<std::string, Botao*> btns;

    bool isPaused;

public:
    LevelFinal(sf::RenderWindow *window, std::stack<State*>* states);
    ~LevelFinal();

    //Functions
    
    void updateColisao();
    void updateEntidade();
    void render(sf::RenderTarget&target);
};
