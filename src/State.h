#pragma once

#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "Entidade.h"
#include "Personagem.h"

#include "Jogador.h"
#include "Personagem.h"

#include "Espadachim.h"
#include "Monstro.h"
#include "Esqueleto.h"

#include "MapaPrincipal.h"
#include "Collision.h"


class State{
protected:
    sf::RenderWindow *window;
    bool quit;
public:
    State(sf::RenderWindow *window);
    virtual ~State();
    
    const bool& getQuit() const;

    virtual void checkQuit();

    virtual void endState();

    virtual void updateKeybinds();
    // virtual void updateColisao()=0;
    //virtual void updateEntidade() = 0;
    virtual void update();
    virtual void render(sf::RenderTarget &target) = 0;
};


