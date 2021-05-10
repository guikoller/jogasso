#pragma once

#include "State.h"
#include "Botao.h"

class LevelBase : public State { 
protected:
    TileMap *mapa;
    Jogador *espadachim;
    Jogador *martelador;

    int placar;
    bool write;
    sf::Text textoPlacar;
    std::ofstream arquivoPlacar;
    
    std::map<std::string, Botao*> btns;
    bool isPaused;
    bool segundoJogador;

    virtual void initEntidade() = 0;
    void iniciaBotao(); 
    void iniciaPlacar();
public:
    LevelBase(sf::RenderWindow *window, std::stack<State*>* states);
    virtual ~LevelBase();

    //Functions
    void salvarPlacar();
    void destroiBotao();
    virtual void updateColisao() = 0;
    virtual void updateEntidade() = 0;
    void updateBotao();
    void updatePlacar();
    virtual void update();
    void renderBotao(sf::RenderTarget &target);
    void renderPlacar(sf::RenderTarget &target);
    virtual void render(sf::RenderTarget&target) = 0;
};
