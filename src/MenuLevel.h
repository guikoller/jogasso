#pragma once

// #include "MenuPrincipal.h"
#include "LevelPrincipal.h"
#include "LevelFinal.h"
#include "Botao.h"

class MenuLevel : public State{
private:

    sf::Text titulo;

    sf::Texture texture;
    sf::Sprite background;
    
    Botao *btn;

    std::map<std::string, Botao*> btns;

    void iniciaBotao();
    void iniciaBackground();
    void iniciaTitulo();
public:
    MenuLevel(sf::RenderWindow *window, std::stack<State*>* states);
    virtual ~MenuLevel();
    void updateBotao();
    void update();
    void renderBotao(sf::RenderTarget &target);
    virtual void render(sf::RenderTarget &target);
};

