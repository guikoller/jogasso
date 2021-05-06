#pragma once

#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "Entidade.h"
#include "Personagem.h"
#include "Espadachim.h"
#include "MapaPrincipal.h"
#include "Collision.h"


class State{
protected:
    sf::RenderWindow *window;
public:
    State(sf::RenderWindow *window);
    virtual ~State();
    
    //virtual void endState() = 0;

    virtual void updateColisao()=0;
    virtual void updateEntidade() = 0;
    virtual void update();
    virtual void render(sf::RenderTarget &target) = 0;
};


