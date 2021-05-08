#pragma once

#include "LevelPrincipal.h"
#include "Botao.h"

class MenuPrincipal : public State{
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
    MenuPrincipal(sf::RenderWindow *window, std::stack<State*>* states);
    virtual ~MenuPrincipal();
    void updateBotao();
    void update();
    void renderBotao(sf::RenderTarget &target);
    virtual void render(sf::RenderTarget &target);
};

