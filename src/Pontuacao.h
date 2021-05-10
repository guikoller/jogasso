#pragma once

// #include "MenuPrincipal.h"
#include "LevelPrincipal.h"
#include "LevelFinal.h"
#include "Botao.h"
#include <string>
#include <sstream>

class Pontuacao : public State{
private:

    sf::Text titulo;

    sf::Text placar;

    sf::Texture texture;
    sf::Sprite background;
    
    Botao *btn;

    std::map<std::string, Botao*> btns;
    void iniciaPlacar();
    void iniciaBotao();
    void iniciaBackground();
    void iniciaTitulo();
public:
    Pontuacao(sf::RenderWindow *window, std::stack<State*>* states);
    virtual ~Pontuacao();
    void updateBotao();
    void update();
    void renderBotao(sf::RenderTarget &target);
    virtual void render(sf::RenderTarget &target);
    std::string readFile();
};

