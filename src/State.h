#pragma once

#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "Entidade.h"
#include "Jogador.h"
#include "Lista.h"

#include "Espadachim.h"
#include "Martelador.h"
#include "Monstro.h"
#include "Esqueleto.h"
#include "Goblin.h"

#include "Caixa.h"
#include "Espinho.h"
#include "Porta.h"
#include "Portal.h"

#include "MapaPrincipal.h"
#include "MapaFinal.h"
#include "Collision.h"
#include <stack>
#include <string>
#include <fstream>

class State{
public:
    std::stack<State*> *states;

    sf::RenderWindow *window;
    bool quit;

    sf::Font fonte;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    void iniciaFontes();
public:
    State(sf::RenderWindow *window, std::stack<State*>* states);
    virtual ~State();
    
    const bool& getQuit() const;
    virtual void checkQuit();
    virtual void endState();
    virtual void updateMousePosition();

    virtual void updateKeybinds();
    virtual void update();
    virtual void render(sf::RenderTarget &target) = 0;
};


