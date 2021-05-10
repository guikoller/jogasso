#pragma once

#include "State.h"
#include "Botao.h"

class LevelBase : public State { 
protected:
    TileMap *mapa;
    Jogador *espadachim;
    Jogador *martelador;
    
    std::map<std::string, Botao*> btns;
    bool isPaused;
    bool segundoJogador;

    virtual void initEntidade() = 0;
    void iniciaBotao();   
public:
    LevelBase(sf::RenderWindow *window, std::stack<State*>* states);
    virtual ~LevelBase();

    //Functions
    void destroiBotao();
    virtual void updateColisao() = 0;
    virtual void updateEntidade() = 0;
    void updateBotao();
    virtual void update();
    void renderBotao(sf::RenderTarget &target);
    virtual void render(sf::RenderTarget&target) = 0;
};
