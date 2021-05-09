#pragma once

#include "State.h"
#include "Botao.h"

class LevelBase : public State { 
protected:
    TileMap *mapa;
    
    std::map<std::string, Botao*> btns;
    bool isPaused;

    virtual void initEntidade() = 0;
    void iniciaBotao();   

public:
    LevelBase(sf::RenderWindow *window, std::stack<State*>* states);
    virtual ~LevelBase();

    //Functions
    void destroiBotao();
    void updateColisao();
    virtual void updateEntidade() = 0;
    void updateBotao();
    void update();
    void renderBotao(sf::RenderTarget &target);
    virtual void render(sf::RenderTarget&target) = 0;
};
